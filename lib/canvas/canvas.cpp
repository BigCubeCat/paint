#include "canvas.hpp"
#include <QWidget>

#include "../common/state.hpp"

Canvas::Canvas(QWidget* parent)
    : QWidget(parent), m_pixmap(QPixmap(1000, 500)) {
    m_pixmap.fill(Qt::white);
}

void Canvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    auto& state = StateSingleton::instance();
    this->resize(state.width(), state.height());

    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);

    if (m_drawing) {
        QPen pen(Qt::gray, 1, Qt::DashLine);
        painter.setPen(pen);
        // TODO(bigcubecat): реализовать алгоритм
        painter.drawLine(m_startPoint, m_currentPoint);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
    if (!(event->buttons() & Qt::LeftButton)) {
        return;
    }
    if (!m_drawing) {
        return;
    }
    m_currentPoint = event->pos();
    update();
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        m_drawing = true;
        m_startPoint = event->pos();
        m_currentPoint = event->pos();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && m_drawing) {
        m_drawing = false;
        QPainter painter(&m_pixmap);
        QPen pen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        painter.drawLine(m_startPoint, event->pos());
        update();
    }
}
