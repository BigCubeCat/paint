#include "canvas.hpp"
#include <qlogging.h>

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

    auto* tool = StateSingleton::instance().tool();
    if (!tool) {
        qDebug() << "Tool is nullptr!";
        return;
    }
    tool->paintEvent(m_pixmap, &painter, event);
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
    if (!(event->buttons() & Qt::LeftButton)) {
        return;
    }

    auto* tool = StateSingleton::instance().tool();
    if (!tool) {
        qDebug() << "Tool is nullptr!";
        return;
    }
    tool->onMouseMove(m_pixmap, event);
    update();
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        auto* tool = StateSingleton::instance().tool();
        if (!tool) {
            qDebug() << "Tool is nullptr!";
            return;
        }
        tool->onMouseDown(m_pixmap, event);
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        auto* tool = StateSingleton::instance().tool();
        if (!tool) {
            qDebug() << "Tool is nullptr!";
            return;
        }
        tool->onMouseUp(m_pixmap, event);
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

void Canvas::resize(int width, int height) {
    QPixmap new_pixmap(width, height);
    new_pixmap.fill(Qt::white);
    QPainter painter(&new_pixmap);

    int orig_width = pixmap().width();
    int orig_height = pixmap().height();

    painter.drawPixmap(m_pixmap.rect(), m_pixmap);
    setPixmap(new_pixmap);
}
