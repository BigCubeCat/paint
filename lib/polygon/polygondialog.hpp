#pragma once

#include "../common/polygon_config.hpp"
#include "../spinslider/spinslider.hpp"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class PolygonDialog;
}
QT_END_NAMESPACE

class PolygonDialog : public QDialog {
    Q_OBJECT
   public:
    explicit PolygonDialog(QWidget* parent = nullptr);
    ~PolygonDialog() override;

    PolygonConfig config();

   private:
    Ui::PolygonDialog* m_ui;
    PolygonConfig m_config;

    SpinSlider m_vert;
    SpinSlider m_width;
    SpinSlider m_radius;
    SpinSlider m_angle;

   public slots:
    void widthChanged(int w);
    void vertChanged(int h);
    void radiusChanged(int r);
    void angleChanged(int a);
};
