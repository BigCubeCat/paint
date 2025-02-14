/*!
 * \file в этом файле описывается класс хранящий состояние 
*/
#pragma once

#include <qcolor.h>
#include <memory>
#include "e_tool.hpp"
#include "i_tool.hpp"

/*!
 * \brief хранит состояние
 * Состояние включает в себя имена файлов, выбранный инструмент и тп
 * Singleton. Thread-Safe
*/
class StateSingleton {
   private:
    StateSingleton() = default;

    std::shared_ptr<ITool> m_current_tool;
    QColor m_current_color;

    int m_width = 600;
    int m_height = 400;

    int m_tool_width;

    int m_count_vert;
    int m_radius;

    e_tool m_selected_tool;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;

    static StateSingleton& instance();
    void setColor(const QColor& color);
    QColor color() const;

    void setGeometry(int w, int h);
    int width() const;
    int height() const;

    void setToolWidth(int width);
    int toolWidth() const;

    void selectTool(e_tool tool);
    e_tool currentTool() const;

    void setRadius(int r);
    int radius() const;

    void setCountVert(int n);
    int countVert() const;
};
