#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ResizeDialog;
}
QT_END_NAMESPACE

class ResizeDialog : public QDialog {
    Q_OBJECT
   public:
    explicit ResizeDialog(QWidget* parent = nullptr);
    ~ResizeDialog() override;

    int width() const;
    int height() const;

   private:
    Ui::ResizeDialog* m_ui;
    int m_width;
    int m_height;

   public slots:
    void widthChanged(int w);
    void heightChanged(int h);
};
