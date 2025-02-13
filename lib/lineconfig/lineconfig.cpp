#include "./lineconfig.hpp"

#include "ui_lineconfig.h"

#include <QSpinBox>

#include "../common/state.hpp"

LineConfig::LineConfig(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::LineConfig) {
    m_ui->setupUi(this);
    connect(m_ui->spinBox, &QSpinBox::valueChanged, this,
            &LineConfig::setWidth);
}

void LineConfig::setWidth(int width) {
    auto& state = StateSingleton::instance();
    state.setToolWidth(width);
}
