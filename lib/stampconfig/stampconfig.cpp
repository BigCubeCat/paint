#include "./stampconfig.hpp"

#include "../common/state.hpp"

#include "ui_stampconfig.h"

StampConfig::StampConfig(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::StampConfig) {
    m_ui->setupUi(this);

    connect(m_ui->countSpin, &QSpinBox::valueChanged, this, &StampConfig::setN);
    connect(m_ui->spinBox, &QSpinBox::valueChanged, this,
            &StampConfig::setRadius);
}

StampConfig::~StampConfig() {
    delete m_ui;
}

void StampConfig::setN(int n) {
    auto& state = StateSingleton::instance();
    state.setCountVert(n);
}

void StampConfig::setRadius(int r) {
    auto& state = StateSingleton::instance();
    state.setRadius(r);
}
