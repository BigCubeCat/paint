#pragma once

#include <qevent.h>
#include "../common/i_tool.hpp"

class Line : public ITool {
   private:
    bool m_drawing = false;
    QPoint m_start;
    QPoint m_current;

   public:
    void onMouseDown(QPixmap& canvas, QMouseEvent* event) override;

    void onMouseMove(QPixmap& canvas, QMouseEvent* event) override;

    void onMouseUp(QPixmap& canvas, QMouseEvent* event) override;

    void paintEvent(QPixmap& canvas, QPainter* painter,
                    QPaintEvent* event) override;
};
