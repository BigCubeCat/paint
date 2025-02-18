#include "./paramwidget.hpp"
#include <qlabel.h>
#include <qlogging.h>

#include "ui_paramwidget.h"

ParamWidget::ParamWidget(QWidget* parent)
    : QWidget(parent),
      m_ui(new Ui::ParamWidget),
      m_line_icon("assets/icons/line.png"),
      m_fill_icon("assets/icons/fill.png"),
      m_poly_icon("assets/icons/shape.png"),
      m_label(this),
      m_line(this),
      m_fill(this) {
    m_ui->setupUi(this);

    m_label.setPixmap(m_line_icon.pixmap(32, 32));

    m_ui->layout->addWidget(&m_label);

    m_ui->layout->addWidget(&m_line);
    m_ui->layout->addWidget(&m_fill);

    m_fill.setHidden(true);
}

ParamWidget::~ParamWidget() {
    delete m_ui;
}

void ParamWidget::setTool(e_tool tool) {
    if (tool == kToolLine) {
        m_label.setPixmap(m_line_icon.pixmap(32, 32));
        m_widget_ptr = &m_line;
        m_line.setHidden(false);
        m_fill.setHidden(true);
        return;
    }
    m_widget_ptr = &m_fill;
    m_line.setHidden(true);
    m_fill.setHidden(false);
    if (tool == kToolFill) {
        m_label.setPixmap(m_fill_icon.pixmap(32, 32));
    } else {
        m_label.setPixmap(m_poly_icon.pixmap(32, 32));
    }
}
