#pragma once

#include <qcolor.h>
#include <QPushButton>
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
    std::vector<QPushButton*> m_buttons;
    std::vector<QColor> m_colors = {
        QColorConstants::Black,   QColorConstants::Red,
        QColorConstants::Yellow,  QColorConstants::Green,
        QColorConstants::Cyan,    QColorConstants::Blue,
        QColorConstants::Magenta, QColorConstants::White,
    };
    int m_current_color_id;

    void setColor(int colorId, QColor newColor);

    void highlight();

    static void styleButton(QPushButton* btn, const QColor& color);

   public slots:
    void clickedBlack();
    void clickedRed();
    void clickedYellow();
    void clickedGreen();
    void clickedCyan();
    void clickedBlue();
    void clickedMagenta();
    void clickedWhite();
    void clickedCustom();
};
