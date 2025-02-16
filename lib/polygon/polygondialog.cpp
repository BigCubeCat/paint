#include "./polygondialog.hpp"
#include <QRadioButton>
#include <QSpinBox>

#include "../common/state.hpp"

#include "ui_polygondialog.h"

PolygonDialog::PolygonDialog(QWidget* parent)
    : QDialog(parent), m_ui(new Ui::PolygonDialog) {
    m_ui->setupUi(this);

    connect(m_ui->widthBox, &QSpinBox::valueChanged, this,
            &PolygonDialog::widthChanged);
    connect(m_ui->vertBox, &QSpinBox::valueChanged, this,
            &PolygonDialog::vertChanged);
    connect(m_ui->radiusBox, &QSpinBox::valueChanged, this,
            &PolygonDialog::radiusChanged);
    connect(m_ui->angleBox, &QSpinBox::valueChanged, this,
            &PolygonDialog::angleChanged);

    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();
    m_ui->widthBox->setValue(config.width);
    m_ui->radiusBox->setValue(config.radius);
    m_ui->angleBox->setValue(config.angle);
    m_ui->vertBox->setValue(config.n);
}

PolygonDialog::~PolygonDialog() {
    delete m_ui;
}

void PolygonDialog::widthChanged(int w) {
    m_config.width = w;
}
void PolygonDialog::vertChanged(int h) {
    m_config.n = h;
}

void PolygonDialog::radiusChanged(int r) {
    m_config.radius = r;
}

void PolygonDialog::angleChanged(int a) {
    m_config.angle = a;
}

PolygonConfig PolygonDialog::config() {
    m_config.isStar = m_ui->star->isChecked();
    m_config.n = m_ui->vertBox->value();
    m_config.angle = m_ui->angleBox->value();
    m_config.width = m_ui->widthBox->value();
    m_config.radius = m_ui->radiusBox->value();
    return m_config;
}
