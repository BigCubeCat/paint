#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow), m_canvas(Canvas(this)) {
    m_ui->setupUi(this);

    m_ui->scrollArea->setWidget(&m_canvas);
}

MainWindow::~MainWindow() {
    delete m_ui;
}
