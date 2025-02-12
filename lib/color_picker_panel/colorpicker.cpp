#include "colorpicker.hpp"
#include <qlogging.h>

#include "ui_colorpicker.h"

#include <QWidget>

ColorPicker::ColorPicker(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::ColorPicker) {
    m_ui->setupUi(this);
    qDebug() << "ColorPicker()"
             << std::to_string(static_cast<int>(m_ui->btnBlack == nullptr));
}

ColorPicker::~ColorPicker() {
    delete m_ui;
}
