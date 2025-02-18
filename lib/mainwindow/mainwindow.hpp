#pragma once

#include <QActionGroup>
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
   private slots:

    void useLine();
    void useFill();
    void useStamp();

    void saveImage();
    void saveImageAs();
    void openImage();

    void resizeCanvas();

    void aboutSlots();
    void helpSlots();

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;

    QActionGroup m_tool_group;

    Canvas m_canvas;
    ColorPicker m_colorpicker;
    ParamWidget m_param_widget;

    std::string m_filename;
    std::string m_format = "PNG";

    void askFilename();
};
