#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class AboutDialog;
}
QT_END_NAMESPACE

class AboutDialog : public QDialog {
    Q_OBJECT
   public:
    explicit AboutDialog(QWidget* parent = nullptr);
    ~AboutDialog() override;

   private:
    Ui::AboutDialog* m_ui;
};
