#pragma once

#include <QMainWindow>

#include "../canvas/canvas.hpp"
#include "../color_picker_panel/colorpicker.hpp"
#include "../paramwidget/paramwidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;

    Canvas m_canvas;
    ColorPicker m_colorpicker;
    ParamWidget m_param_widget;
};
