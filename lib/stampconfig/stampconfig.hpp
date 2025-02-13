#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class StampConfig;
}
QT_END_NAMESPACE

class StampConfig : public QWidget {
    Q_OBJECT
   public:
    explicit StampConfig(QWidget* parent = nullptr);
    ~StampConfig() override;

   private:
    Ui::StampConfig* m_ui;
    int m_count;

   public slots:
    void setN(int n);
    void setRadius(int r);
};
