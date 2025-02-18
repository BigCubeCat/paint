#include "./fill.hpp"
#include <qlogging.h>
#include <QPainter>
#include <stack>

#include "../common/state.hpp"

void Fill::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_point = event->pos();
    auto& state = StateSingleton::instance();
    span(canvas, state.color());
}
//
// void Fill::paintEvent(QPixmap& canvas, [[maybe_unused]] QPainter* painter,
//                       [[maybe_unused]] QPaintEvent* event) {}
//
void Fill::span(QPixmap& canvas, const QColor& color) {
    QImage img = canvas.toImage();
    QColor old_color = img.pixelColor(m_point);
    if (old_color == color)
        return;

    std::stack<QPoint> stack;
    stack.push(m_point);

    while (!stack.empty()) {
        QPoint p = stack.top();
        stack.pop();

        int x = p.x();
        int y = p.y();
        if (x < 0 || x >= img.width() || y < 0 || y >= img.height())
            continue;
        if (img.pixelColor(x, y) != old_color)
            continue;

        int left = x;
        int right = x;
        while (left > 0 && img.pixelColor(left - 1, y) == old_color)
            left--;
        while (right < img.width() - 1 &&
               img.pixelColor(right + 1, y) == old_color)
            right++;

        for (int i = left; i <= right; ++i) {
            img.setPixelColor(i, y, color);
        }

        for (int i = left; i <= right; ++i) {
            if (y > 0 && img.pixelColor(i, y - 1) == old_color)
                stack.emplace(i, y - 1);
            if (y < img.height() - 1 && img.pixelColor(i, y + 1) == old_color)
                stack.emplace(i, y + 1);
        }
    }

    canvas.convertFromImage(img);
}
