#pragma once

#include <QSlider>
#include <QSpinBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SpinSlider;
}
QT_END_NAMESPACE

class SpinSlider : public QWidget {
    Q_OBJECT
   public:
    explicit SpinSlider(QWidget* parent, int minimum, int maximum, int value);
    ~SpinSlider() override;

    void setValue(int value);
    int value() const { return m_value; }

   private slots:
    void valueChanged(int value);

   public:
   signals:
    void onValueChanged(int value);

   private:
    Ui::SpinSlider* m_ui;
    int m_value;
    int m_max;
    int m_min;
};
