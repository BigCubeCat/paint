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

    /// установить радиус
    void setRadius(int r);
    /// радиус из конфига
    int radius() const;

    /// установить число вершин
    void setCountVert(int n);
    /// число вершин из конфига
    int countVert() const;

    /// Возращает указатель на текцщий инструмент
    ITool* tool();
};
