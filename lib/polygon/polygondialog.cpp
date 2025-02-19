#include "./polygondialog.hpp"
#include <QRadioButton>
#include <QSpinBox>

#include "../common/state.hpp"

#include "ui_polygondialog.h"

PolygonDialog::PolygonDialog(QWidget* parent)
    : QDialog(parent),
      m_ui(new Ui::PolygonDialog),
      m_vert(this, 3, 20, 5),
      m_width(this, 1, 1000, 3),
      m_radius(this, 1, 1000, 128),
      m_angle(this, 0, 360, 0) {
    m_ui->setupUi(this);

    m_ui->vert->addWidget(&m_vert);
    m_ui->width->addWidget(&m_width);
    m_ui->radius->addWidget(&m_radius);
    m_ui->angle->addWidget(&m_angle);

    connect(&m_vert, &SpinSlider::onValueChanged, this,
            &PolygonDialog::vertChanged);
    connect(&m_width, &SpinSlider::onValueChanged, this,
            &PolygonDialog::widthChanged);
    connect(&m_radius, &SpinSlider::onValueChanged, this,
            &PolygonDialog::radiusChanged);
    connect(&m_angle, &SpinSlider::onValueChanged, this,
            &PolygonDialog::angleChanged);

    auto& state = StateSingleton::instance();
    auto config = state.polygonConfig();
    m_ui->star->setChecked(config.isStar);
    m_ui->poly->setChecked(!config.isStar);

    m_vert.setValue(config.n);
    m_width.setValue(config.width);
    m_radius.setValue(config.radius);
    m_angle.setValue(config.angle);
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
    m_config.n = m_vert.value();
    m_config.angle = m_angle.value();
    m_config.width = m_width.value();
    m_config.radius = m_radius.value();
    return m_config;
}
