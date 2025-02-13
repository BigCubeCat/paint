/*!
 * \file в этом файле описывается класс хранящий состояние 
*/
#pragma once

#include <qcolor.h>
#include <memory>
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

    int m_width;
    int m_height;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;

    static StateSingleton& instance();
    void setColor(const QColor& color);
    QColor color() const;

    void setGeometry(int w, int h);
    int width() const;
    int height() const;
};
