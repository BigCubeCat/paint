#pragma once

#include <QColor>

/*!
 * \brief Интерфейс инстумента (наприме заливка, линия и тп)
*/
class ITool {
   public:
    virtual void onMouseDown(int row, int col) = 0;

    virtual void onMouseMove(int row, int col) = 0;

    virtual void onMouseUp(int row, int col) = 0;

    virtual void setColor(const QColor& color) = 0;

    virtual void setWidth(int width) = 0;
};
