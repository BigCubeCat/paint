#include "./polygondialog.hpp"
#include <QRadioButton>
#include <QSpinBox>

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
    return m_config;
}
