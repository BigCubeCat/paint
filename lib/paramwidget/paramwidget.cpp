#include "./paramwidget.hpp"
#include <qlogging.h>

#include "ui_paramwidget.h"

ParamWidget::ParamWidget(QWidget* parent)
    : QWidget(parent),
      m_ui(new Ui::ParamWidget),
      m_line(this),
      m_fill(this),
      m_stamp(this) {
    m_ui->setupUi(this);
    m_ui->layout->addWidget(&m_line);
    m_ui->layout->addWidget(&m_fill);
    m_ui->layout->addWidget(&m_stamp);

    m_fill.setHidden(true);
    m_stamp.setHidden(true);
}

ParamWidget::~ParamWidget() {
    delete m_ui;
}

void ParamWidget::setTool(e_tool tool) {
    if (tool == kToolLine) {
        m_widget_ptr = &m_line;
        m_line.setHidden(false);
        m_stamp.setHidden(true);
        m_fill.setHidden(true);
    } else if (tool == kToolFill) {
        m_widget_ptr = &m_fill;
        m_fill.setHidden(false);
        m_line.setHidden(true);
        m_stamp.setHidden(true);
    } else {
        m_widget_ptr = &m_stamp;
        m_stamp.setHidden(false);
        m_line.setHidden(true);
        m_fill.setHidden(true);
    }
}
