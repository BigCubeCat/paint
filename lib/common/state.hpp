/*!
 * \file в этом файле описывается класс хранящий состояние 
*/
#pragma once

#include <qcolor.h>
#include <memory>
#include "e_tool.hpp"
#include "i_tool.hpp"
#include "polygon_config.hpp"

/*!
 * \brief хранит состояние
 * Состояние включает в себя имена файлов, выбранный инструмент и тп
 * Singleton. Thread-Safe
*/
class StateSingleton {
   private:
    StateSingleton() = default;

    std::shared_ptr<ITool> m_current_tool;
    QColor m_current_color = QColorConstants::Black;

    int m_width = 600;
    int m_height = 400;

    int m_tool_width = 1;

    e_tool m_selected_tool;
    PolygonConfig m_poly_config;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;

    /// вернуть сущность объекта
    static StateSingleton& instance();
    /// установить цвет
    void setColor(const QColor& color);
    /// текущий цвет
    QColor color() const;

    /// установить геоментрию холста
    void setGeometry(int w, int h);
    /// ширина холста
    int width() const;
    /// высота холста
    int height() const;

    /// установить ширину инструмента
    void setToolWidth(int width);
    /// ширина инструмента
    int toolWidth() const;

    /// установаить инструмент
    void selectTool(e_tool tool);
    /// возращает тэг текущего инструмента
    e_tool currentTool() const;

    PolygonConfig polygonConfig();

    void setPolygonConfig(PolygonConfig config);

    /// Возращает указатель на текцщий инструмент
    ITool* tool();
};
