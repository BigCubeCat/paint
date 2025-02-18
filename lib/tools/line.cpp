#include "./line.hpp"
#include <QPainter>

#include "../common/state.hpp"

void Line::onMouseUp(QPixmap& canvas, [[maybe_unused]] QMouseEvent* event) {
    if (m_drawing) {
        m_drawing = false;
        QPainter painter(&canvas);
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::DashLine);
        painter.setPen(pen);
        drawLineBresenham(&painter, m_start.x(), m_start.y(), m_current.x(),
                          m_current.y());
    }
}

void Line::onMouseMove([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    if (!m_drawing) {
        return;
    }
    m_current = event->pos();
}

void Line::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_drawing = true;
    m_start = event->pos();
    m_current = event->pos();
}

void Line::paintEvent([[maybe_unused]] QPixmap& canvas, QPainter* painter,
                      [[maybe_unused]] QPaintEvent* event) {
    if (m_drawing) {
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::DashLine);
        painter->setPen(pen);
        // TODO(bigcubecat): реализовать алгоритм
        drawLineBresenham(painter, m_start.x(), m_start.y(), m_current.x(),
                          m_current.y());
    }
}

void Line::drawLineBresenham(QPainter* painter, int x1, int y1, int x2,
                             int y2) {
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (x1 != x2 || y1 != y2) {
        painter->drawPoint(x1, y1);
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y1 += sy;
        }
    }
}
