#pragma once

#include <qevent.h>
#include "../common/i_tool.hpp"

class Fill : public ITool {
   private:
    QPoint m_point;
    void span(QPixmap& canvas, const QColor& color);

   public:
    void onMouseDown(QPixmap& canvas, QMouseEvent* event) override;

    void onMouseMove(QPixmap& canvas, QMouseEvent* event) override {}

    void onMouseUp(QPixmap& canvas, QMouseEvent* event) override {}

    void paintEvent(QPixmap& canvas, QPainter* painter,
                    QPaintEvent* event) override {}
};
