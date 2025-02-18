#include "./fill.hpp"
#include <qlogging.h>
#include <QPainter>
#include <stack>

#include "../common/state.hpp"
#include "../common/utils.hpp"

void Fill::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_point = event->pos();
    auto& state = StateSingleton::instance();
    span(canvas, state.color());
}

void Fill::span(QPixmap& canvas, const QColor& color) {
    auto start = current_unixtime;
    QImage img = canvas.toImage();
    QColor old_color = img.pixelColor(m_point);
    if (old_color == color)
        return;

    std::stack<QPoint> stack;
    stack.push(m_point);
    int width = img.width();
    int height = img.height();
    int x_border = width - 1;
    int y_border = height - 1;

    while (!stack.empty()) {
        QPoint p = stack.top();
        stack.pop();

        int x = p.x();
        int y = p.y();
        /// такой цикл с разделением на 2 потка позволил ускорить алгоритм примерно на 30%
        int coords[2] = {x, x};
        int dx[2] = {-1, 1};
#pragma omp parallel for num_threads(2)
        for (int i = 0; i < 2; ++i) {
            while (coords[i] > 0 && coords[i] < x_border &&
                   img.pixelColor(coords[i] + dx[i], y) == old_color)
                coords[i] += dx[i];
        }

        for (int i = coords[0]; i <= coords[1]; ++i) {
            img.setPixelColor(i, y, color);
            if (y > 0 && img.pixelColor(i, y - 1) == old_color)
                stack.emplace(i, y - 1);
            if (y < y_border && img.pixelColor(i, y + 1) == old_color)
                stack.emplace(i, y + 1);
        }
    }

    canvas.convertFromImage(img);
    auto finish = current_unixtime;
    qDebug() << "time spent: " << (finish - start) / 1000000;
}
