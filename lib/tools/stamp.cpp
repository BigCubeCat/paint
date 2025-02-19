#include "./stamp.hpp"
#include <qlogging.h>
#include <QPainter>

#include "../common/state.hpp"

void Stamp::onMouseUp(QPixmap& canvas, [[maybe_unused]] QMouseEvent* event) {
    if (m_drawing) {
        m_drawing = false;
        QPainter painter(&canvas);
        auto& state = StateSingleton::instance();
        auto config = state.polygonConfig();
        QPen pen(state.color(), config.width, Qt::SolidLine);
        painter.setPen(pen);
        draw(&painter);
    }
}

void Stamp::onMouseMove([[maybe_unused]] QPixmap& canvas,
                        [[maybe_unused]] QMouseEvent* event) {}

void Stamp::onMouseDown([[maybe_unused]] QPixmap& canvas, QMouseEvent* event) {
    m_drawing = true;
    m_point = event->pos();
}

void Stamp::paintEvent([[maybe_unused]] QPixmap& canvas, QPainter* painter,
                       [[maybe_unused]] QPaintEvent* event) {
    if (!m_drawing)
        return;
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();
    QPen pen(state.color(), config.width, Qt::SolidLine);
    painter->setPen(pen);
    draw(painter);
}

void Stamp::draw(QPainter* painter) {
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();
    if (config.isStar) {
        star(painter);
    } else {
        polygon(painter);
    }
}

void Stamp::polygon(QPainter* painter) {
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();

    double start_angle = config.angle * (M_PI / 180);  // перевод угла в радианы
    auto angle_step = 2 * M_PI / config.n;
    QPoint prev_point(m_point.x() + (config.radius * cos(start_angle)),
                      m_point.y() + (config.radius * sin(start_angle)));

    for (int i = 1; i <= config.n; ++i) {
        auto rotation = start_angle + (i * angle_step);
        QPoint new_point(m_point.x() + (config.radius * cos(rotation)),
                         m_point.y() + (config.radius * sin(rotation)));
        painter->drawLine(prev_point, new_point);
        prev_point = new_point;
    }
}

void Stamp::star(QPainter* painter) {
    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();

    double angle_step = M_PI / config.n;
    double start_angle = config.angle * (M_PI / 180);

    // Коэффициент для внутреннего радиуса.
    double inner_ratio = 0.5;
    int outer_radius = config.radius;
    int inner_radius = static_cast<int>(config.radius * inner_ratio);

    std::vector<QPoint> star_points;
    // Вычисляем 2*points вершин: четные - внешние, нечетные - внутренние
    for (int i = 0; i < 2 * config.n; ++i) {
        int r = (i % 2 == 0) ? outer_radius : inner_radius;
        double current_angle = start_angle + (i * angle_step);
        QPoint pt(m_point.x() + (r * cos(current_angle)),
                  m_point.y() + (r * sin(current_angle)));
        star_points.push_back(pt);
    }

    // Соединяем последовательно вершины, чтобы получилась звезда
    for (size_t i = 0; i < star_points.size(); ++i) {
        QPoint p1 = star_points[i];
        QPoint p2 = star_points[(i + 1) % star_points.size()];
        painter->drawLine(p1, p2);
    }
}
