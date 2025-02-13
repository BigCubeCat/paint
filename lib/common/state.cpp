#include "state.hpp"

StateSingleton& StateSingleton::instance() {
    static StateSingleton inst;
    return inst;
}

void StateSingleton::setColor(const QColor& color) {
    m_current_color = color;
    if (m_current_tool) {
        m_current_tool->setColor(color);
    }
}

QColor StateSingleton::color() const {
    return m_current_color;
}

int StateSingleton::width() const {
    return m_width;
}

int StateSingleton::height() const {
    return m_height;
}

void StateSingleton::setGeometry(int w, int h) {
    m_width = w;
    m_height = h;
}
