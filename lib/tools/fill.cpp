#include "./fill.hpp"
#include <qlogging.h>
#include <QPainter>
#include <stack>

#include "../common/state.hpp"
#include "../common/utils.hpp"

namespace {
void scanSpan(const QImage& image, const QColor color, const QPoint& begin,
              const QPoint& end, std::stack<QPoint>& stack) {
    bool could_add_span = true;
    for (QPoint i = begin; i != end; i.setX(i.x() + 1)) {
        if (image.pixelColor(i) != color) {
            could_add_span = true;
        } else if (could_add_span) {
            stack.push(i);
            could_add_span = false;
        }
    }
}
};  // namespace

void Fill::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_point = event->pos();
    auto& state = StateSingleton::instance();
    span(canvas, state.color());
}

void Fill::span(QPixmap& canvas, const QColor& color) {
    QImage img = canvas.toImage();
    QColor old_color = img.pixelColor(m_point);
    if (old_color == color)
        return;
    std::stack<QPoint> stack;
    stack.push(m_point);
    while (!stack.empty()) {
        QPoint right = stack.top();
        stack.pop();
        QPoint left = right + QPoint(-1, 0);
        while (left.x() >= 0 && img.pixelColor(left) == color) {
            img.setPixelColor(left, color);
            left += QPoint(-1, 0);
        }
        left += QPoint(1, 0);
        while (right.x() < img.width() && img.pixelColor(right) == color) {
            img.setPixelColor(right, color);
            right = right + QPoint(1, 0);
        }
        if (left.y() + 1 < img.height())
            scanSpan(img, color, left + QPoint(0, 1), right + QPoint(0, 1),
                     stack);
        if (left.y() - 1 >= 0)
            scanSpan(img, color, left + QPoint(0, -1), right + QPoint(0, -1),
                     stack);
    }
}
