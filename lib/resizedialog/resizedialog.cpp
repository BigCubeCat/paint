#include "./resizedialog.hpp"
#include <qlogging.h>

#include "ui_resizedialog.h"

#include "../common/state.hpp"

ResizeDialog::ResizeDialog(QWidget* parent)
    : QDialog(parent), m_ui(new Ui::ResizeDialog) {
    m_ui->setupUi(this);

    auto& state = StateSingleton::instance();
    m_ui->widthBox->setValue(state.width());
    m_ui->heightBox->setValue(state.height());

    connect(m_ui->widthBox, &QSpinBox::valueChanged, this,
            &ResizeDialog::widthChanged);
    connect(m_ui->heightBox, &QSpinBox::valueChanged, this,
            &ResizeDialog::heightChanged);
}

ResizeDialog::~ResizeDialog() {
    delete m_ui;
}

void ResizeDialog::widthChanged(int w) {
    m_width = w;
}

void ResizeDialog::heightChanged(int h) {
    m_height = h;
}

int ResizeDialog::width() const {
    return m_width;
}

int ResizeDialog::height() const {
    return m_height;
}
