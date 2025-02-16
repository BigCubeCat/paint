#pragma once

#include <QColor>
#include <QMouseEvent>
#include <QPixmap>

/*!
 * \brief Интерфейс инстумента (наприме заливка, линия и тп)
*/
class ITool {
   public:
    virtual void onMouseDown(QPixmap& canvas, QMouseEvent* event) = 0;

    virtual void onMouseMove(QPixmap& canvas, QMouseEvent* event) = 0;

    virtual void onMouseUp(QPixmap& canvas, QMouseEvent* event) = 0;

    virtual void paintEvent(QPixmap& canvas, QPainter* painter,
                            QPaintEvent* event) = 0;
};
