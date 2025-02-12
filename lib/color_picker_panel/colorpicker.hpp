#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ColorPicker;
}
QT_END_NAMESPACE

/*!
 * \brief Виджет, который позволяет выбрать текущий цвет
*/
class ColorPicker : public QWidget {
   public:
    explicit ColorPicker(QWidget* parent = nullptr);
    ~ColorPicker() override;

   private:
    Ui::ColorPicker* m_ui;
};
