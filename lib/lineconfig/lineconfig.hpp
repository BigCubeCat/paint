#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LineConfig;
}
QT_END_NAMESPACE

class LineConfig : public QWidget {
    Q_OBJECT
   public:
    explicit LineConfig(QWidget* parent = nullptr);

   private:
    Ui::LineConfig* m_ui;

   public slots:
    void setWidth(int width);
};
