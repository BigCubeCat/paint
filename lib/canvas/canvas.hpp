#pragma once

#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class Canvas : public QWidget {
   private:
    bool m_drawing;
    QPixmap m_pixmap;
    QPoint m_lastPoint;

    QPoint m_startPoint;
    QPoint m_currentPoint;

    std::string m_filename;

   public:
    explicit Canvas(QWidget* parent = nullptr);
    Canvas(const Canvas&) = delete;
    Canvas(Canvas&&) = delete;
    Canvas& operator=(const Canvas&) = delete;
    Canvas& operator=(Canvas&&) = delete;

    QPixmap pixmap();
    void setPixmap(QPixmap pixmap);

   protected:
    // Обрабатываем нажатие левой кнопки мыши
    void mousePressEvent(QMouseEvent* event) override;
    // Обрабатываем перемещение мыши при зажатой левой кнопке
    void mouseMoveEvent(QMouseEvent* event) override;
    // По отпусканию кнопки прекращаем рисование
    void mouseReleaseEvent(QMouseEvent* event) override;
    // Отрисовка содержимого виджета (наш QPixmap)
    void paintEvent(QPaintEvent* event) override;
};
