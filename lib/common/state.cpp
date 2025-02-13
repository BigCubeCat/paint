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

void StateSingleton::setToolWidth(int width) {
    m_tool_width = width;
    if (m_current_tool) {
        m_current_tool->setWidth(width);
    }
}

int StateSingleton::toolWidth() const {
    return m_tool_width;
}

void StateSingleton::selectTool(e_tool tool) {
    m_selected_tool = tool;
}

e_tool StateSingleton::currentTool() const {
    return m_selected_tool;
}

void StateSingleton::setRadius(int r) {
    m_radius = r;
}

int StateSingleton::radius() const {
    return m_radius;
}

void StateSingleton::setCountVert(int n) {
    m_count_vert = n;
}

int StateSingleton::countVert() const {
    return m_count_vert;
}
