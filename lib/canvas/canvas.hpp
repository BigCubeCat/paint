#pragma once

#include <QWidget>

class Canvas : public QWidget {
   public:
    explicit Canvas(QWidget* parent = nullptr);
    Canvas(const Canvas&) = delete;
    Canvas(Canvas&&) = delete;
    Canvas& operator=(const Canvas&) = delete;
    Canvas& operator=(Canvas&&) = delete;
};
