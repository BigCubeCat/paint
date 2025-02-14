#include "canvas.hpp"

#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>
#include <utility>

#include "../common/state.hpp"

Canvas::Canvas(QWidget* parent) : QWidget(parent), m_pixmap(QPixmap(600, 400)) {
    reset();
    setFixedSize(m_pixmap.size());
}

void Canvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    auto& state = StateSingleton::instance();

    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);

    if (m_drawing) {
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::DashLine);
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
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::SolidLine, Qt::RoundCap,
                 Qt::RoundJoin);
        painter.setPen(pen);
        painter.drawLine(m_startPoint, event->pos());
        update();
    }
}

QPixmap Canvas::pixmap() {
    return m_pixmap;
}

void Canvas::setPixmap(QPixmap pixmap) {
    auto& state = StateSingleton::instance();
    m_pixmap = std::move(pixmap);
    state.setGeometry(m_pixmap.width(), m_pixmap.height());
    setFixedSize(m_pixmap.size());
    update();
}

void Canvas::reset() {
    m_pixmap.fill(Qt::white);
}
