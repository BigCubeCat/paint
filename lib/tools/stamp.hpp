#pragma once

#include <qevent.h>
#include "../common/i_tool.hpp"

class Stamp : public ITool {
   private:
    bool m_drawing = false;
    QPoint m_point;

    void draw(QPainter* painter);

    void polygon(QPainter* painter);

    void star(QPainter* painter);

   public:
    void onMouseUp(QPixmap& canvas, QMouseEvent* event) override;

    void onMouseDown(QPixmap& canvas, QMouseEvent* event) override;

    void onMouseMove(QPixmap& canvas, QMouseEvent* event) override;

    void paintEvent(QPixmap& canvas, QPainter* painter,
                    QPaintEvent* event) override;
};
