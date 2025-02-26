#include "state.hpp"

#include "../tools/fill.hpp"
#include "../tools/line.hpp"
#include "../tools/stamp.hpp"

#include <QDebug>

StateSingleton& StateSingleton::instance() {
    static StateSingleton inst;
    if (inst.tool() == nullptr) {
        inst.selectTool(kToolLine);
    }
    return inst;
}

void StateSingleton::setColor(const QColor& color) {
    m_current_color = color;
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
}

int StateSingleton::toolWidth() const {
    return m_tool_width;
}

void StateSingleton::selectTool(e_tool tool) {
    m_selected_tool = tool;
    if (m_selected_tool == kToolLine) {
        m_current_tool = std::make_shared<Line>();
    } else if (m_selected_tool == kToolFill) {
        m_current_tool = std::make_shared<Fill>();
    } else {
        m_current_tool = std::make_shared<Stamp>();
    }
}

e_tool StateSingleton::currentTool() const {
    return m_selected_tool;
}

ITool* StateSingleton::tool() {
    return m_current_tool.get();
}

PolygonConfig StateSingleton::polygonConfig() {
    return m_poly_config;
}

void StateSingleton::setPolygonConfig(PolygonConfig config) {
    m_poly_config = config;
    qDebug() << config.isStar << " " << config.n << " " << config.radius << " "
             << config.width << " " << config.angle;
}
