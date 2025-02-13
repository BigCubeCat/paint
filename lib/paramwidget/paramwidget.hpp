#pragma once

#include <QWidget>

#include "../common/e_tool.hpp"
#include "../lineconfig/lineconfig.hpp"
#include "../stampconfig/stampconfig.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class ParamWidget;
}
QT_END_NAMESPACE

class ParamWidget : public QWidget {
    Q_OBJECT
   public:
    explicit ParamWidget(QWidget* parent = nullptr);
    ~ParamWidget() override;

   private:
    Ui::ParamWidget* m_ui;
    QWidget* m_widget_ptr;
    LineConfig m_line;
    QWidget m_fill;  // заливка не требует доп настроек
    StampConfig m_stamp;

   public slots:
    void setTool(e_tool tool);
};
