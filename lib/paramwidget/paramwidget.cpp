#include "./paramwidget.hpp"

#include "ui_paramwidget.h"

ParamWidget::ParamWidget(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::ParamWidget), m_line(this), m_fill(this) {
    m_ui->setupUi(this);
    m_widget_ptr = &m_line;
    m_ui->layout->addWidget(m_widget_ptr);
}

ParamWidget::~ParamWidget() {
    delete m_ui;
}

void ParamWidget::setTool(e_tool tool) {
    if (tool == kToolLine) {
        m_widget_ptr = &m_line;
    } else if (tool == kToolFill) {
        m_widget_ptr = &m_fill;
    } else {
    }
}
