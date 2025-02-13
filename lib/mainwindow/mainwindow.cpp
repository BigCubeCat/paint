#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_canvas(Canvas(this)),
      m_colorpicker(ColorPicker(this)) {
    m_ui->setupUi(this);

    m_ui->scrollArea->setWidget(&m_canvas);

    m_ui->toolBar->addActions(m_ui->menuFile->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuTools->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addWidget(&m_colorpicker);
}

MainWindow::~MainWindow() {
    delete m_ui;
}
