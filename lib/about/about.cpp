#include "./about.hpp"
#include <qpainter.h>
#include <qpixmap.h>

#include "ui_about.h"

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent), m_ui(new Ui::AboutDialog) {
    m_ui->setupUi(this);
}

AboutDialog::~AboutDialog() {
    delete m_ui;
}
