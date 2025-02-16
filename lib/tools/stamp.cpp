#include "./stamp.hpp"
#include <qlogging.h>
#include <QPainter>

#include "../common/state.hpp"

void Stamp::onMouseUp(QPixmap& canvas, [[maybe_unused]] QMouseEvent* event) {
    if (m_drawing) {
        m_drawing = false;
        QPainter painter(&canvas);
        auto& state = StateSingleton::instance();
        QPen pen(state.color(), state.toolWidth(), Qt::SolidLine);
        painter.setPen(pen);
        star(&painter);
    }
}

void Stamp::onMouseMove(QPixmap& canvas, [[maybe_unused]] QMouseEvent* event) {}

void Stamp::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_drawing = true;
    m_point = event->pos();
}

void Stamp::paintEvent([[maybe_unused]] QPixmap& canvas, QPainter* painter,
                       [[maybe_unused]] QPaintEvent* event) {
    if (!m_drawing)
        return;
    auto& state = StateSingleton::instance();
    QPen pen(state.color(), state.toolWidth(), Qt::SolidLine);
    painter->setPen(pen);
    star(painter);
}

void Stamp::polygon(QPainter* painter) {
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();

    auto angle_step = 2 * M_PI / config.n;
    QPoint prev_point(m_point.x() + (config.radius * cos(0)),
                      m_point.y() + (config.radius * sin(0)));

    for (int i = 1; i <= config.n; ++i) {
        QPoint new_point(m_point.x() + (config.radius * cos(i * angle_step)),
                         m_point.y() + (config.radius * sin(i * angle_step)));
        painter->drawLine(prev_point, new_point);
        prev_point = new_point;
    }
}

void Stamp::star(QPainter* painter) {
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();

    double angle_step = M_PI / config.n;
    int outer_radius = config.radius;
    int inner_radius = config.radius / 2;

    std::vector<QPoint> star_points;
    for (int i = 0; i < 2 * config.n; ++i) {
        int r = (i % 2 == 0) ? outer_radius : inner_radius;
        double angle = i * angle_step;
        star_points.emplace_back(m_point.x() + (r * cos(angle)),
                                 m_point.y() + (r * sin(angle)));
    }

    for (size_t i = 0; i < star_points.size(); ++i) {
        QPoint p1 = star_points[i];
        QPoint p2 = star_points[(i + 2) % star_points.size()];
        painter->drawLine(p1, p2);
    }
}
