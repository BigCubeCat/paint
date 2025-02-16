#include "./line.hpp"
#include <QPainter>

#include "../common/state.hpp"

void Line::onMouseUp(QPixmap& canvas, QMouseEvent* event) {
    if (m_drawing) {
        m_drawing = false;
        QPainter painter(&canvas);
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::SolidLine, Qt::RoundCap,
                 Qt::RoundJoin);
        painter.setPen(pen);
        painter.drawLine(m_start, event->pos());
    }
}

void Line::onMouseMove(QPixmap& canvas, QMouseEvent* event) {
    if (!m_drawing) {
        return;
    }
    m_current = event->pos();
}

void Line::onMouseDown(QPixmap& canvas, QMouseEvent* event) {
    m_drawing = true;
    m_start = event->pos();
    m_current = event->pos();
}

void Line::paintEvent(QPixmap& canvas, QPainter* painter, QPaintEvent* event) {
    if (m_drawing) {
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::DashLine);
        painter->setPen(pen);
        // TODO(bigcubecat): реализовать алгоритм
        painter->drawLine(m_start, m_current);
    }
}
