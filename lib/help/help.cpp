#include "./help.hpp"
#include <qpainter.h>
#include <qpixmap.h>

#include "ui_help.h"

HelpDialog::HelpDialog(QWidget* parent)
    : QDialog(parent), m_ui(new Ui::HelpDialog) {
    m_ui->setupUi(this);
}

HelpDialog::~HelpDialog() {
    delete m_ui;
}
