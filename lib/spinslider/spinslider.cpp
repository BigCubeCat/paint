#include "./spinslider.hpp"
#include <qlabel.h>
#include <qlogging.h>

#include <algorithm>

#include "ui_spinslider.h"

SpinSlider::SpinSlider(QWidget* parent, int minimum, int maximum, int value)
    : QWidget(parent),
      m_ui(new Ui::SpinSlider),
      m_value(value),
      m_max(maximum),
      m_min(minimum) {
    m_ui->setupUi(this);

    m_ui->horizontalSlider->setMinimum(m_min);
    m_ui->horizontalSlider->setMaximum(m_max);
    m_ui->horizontalSlider->setValue(m_value);

    m_ui->spinBox->setMinimum(m_min);
    m_ui->spinBox->setMaximum(m_max);
    m_ui->spinBox->setValue(m_value);

    connect(m_ui->spinBox, &QSpinBox::valueChanged, this,
            &SpinSlider::valueChanged);

    connect(m_ui->horizontalSlider, &QSlider::valueChanged, this,
            &SpinSlider::valueChanged);
}

SpinSlider::~SpinSlider() {
    delete m_ui;
}

void SpinSlider::valueChanged(int value) {
    m_value = value;
    m_value = std::min(m_value, m_max);
    m_value = std::max(m_value, m_min);
    m_ui->spinBox->setValue(m_value);
    m_ui->horizontalSlider->setValue(m_value);
    emit onValueChanged(m_value);
}

void SpinSlider::setValue(int value) {
    m_value = value;
    m_value = std::min(m_value, m_max);
    m_value = std::max(m_value, m_min);
}
