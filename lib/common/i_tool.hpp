#pragma once

#include <QColor>

/*!
 * \brief Интерфейс инстумента (наприме заливка, линия и тп)
*/
class ITool {
   public:
    /// Стандартное применение без аргументов
    virtual void apply() = 0;

    // Применить инстурмент к указанному пикселю
    virtual void apply(int row, int col) = 0;

    virtual void setColor(const QColor& color) = 0;
};
