#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "../common/state.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_canvas(Canvas(this)),
      m_colorpicker(ColorPicker(this)),
      m_param_widget(ParamWidget(this)) {
    m_ui->setupUi(this);

    m_ui->scrollArea->setWidget(&m_canvas);

    m_ui->toolBar->addActions(m_ui->menuFile->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuTools->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addWidget(&m_colorpicker);

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addWidget(&m_param_widget);

    connect(m_ui->actionLine, &QAction::triggered, this, &MainWindow::useLine);
    connect(m_ui->actionFill, &QAction::triggered, this, &MainWindow::useFill);
    connect(m_ui->actionStamp, &QAction::triggered, this,
            &MainWindow::useStamp);
}

MainWindow::~MainWindow() {
    delete m_ui;
}

/* СЛОТЫ */

void MainWindow::useLine() {
    auto& state = StateSingleton::instance();
    state.selectTool(kToolLine);
    m_param_widget.setTool(kToolLine);
}
void MainWindow::useFill() {
    auto& state = StateSingleton::instance();
    state.selectTool(kToolFill);
    m_param_widget.setTool(kToolFill);
}

void MainWindow::useStamp() {
    auto& state = StateSingleton::instance();
    state.selectTool(kToolStamp);
    m_param_widget.setTool(kToolStamp);
}
