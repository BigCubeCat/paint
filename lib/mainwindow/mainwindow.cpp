#include "mainwindow.hpp"
#include <qlogging.h>
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpinBox>

#include "../about/about.hpp"
#include "../common/state.hpp"
#include "../help/help.hpp"
#include "../polygon/polygondialog.hpp"
#include "../resizedialog/resizedialog.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_tool_group(this),
      m_canvas(Canvas(this)),
      m_colorpicker(ColorPicker(this)),
      m_param_widget(ParamWidget(this)) {
    m_ui->setupUi(this);

    m_ui->scrollArea->setWidget(&m_canvas);

    m_ui->toolBar->addActions(m_ui->menuFile->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuTools->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuView->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addWidget(&m_colorpicker);

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addWidget(&m_param_widget);

    connect(m_ui->actionOpen, &QAction::triggered, this,
            &MainWindow::openImage);
    connect(m_ui->actionSave, &QAction::triggered, this,
            &MainWindow::saveImage);
    connect(m_ui->actionSave_As, &QAction::triggered, this,
            &MainWindow::saveImageAs);

    connect(m_ui->actionLine, &QAction::triggered, this, &MainWindow::useLine);
    connect(m_ui->actionFill, &QAction::triggered, this, &MainWindow::useFill);
    connect(m_ui->actionStamp, &QAction::triggered, this,
            &MainWindow::useStamp);

    connect(m_ui->actionResize, &QAction::triggered, this,
            &MainWindow::resizeCanvas);
    connect(m_ui->actionReset, &QAction::triggered, &m_canvas, &Canvas::reset);

    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);

    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);

    m_tool_group.addAction(m_ui->actionLine);
    m_tool_group.addAction(m_ui->actionFill);
    m_tool_group.addAction(m_ui->actionStamp);
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
    auto dialog = PolygonDialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        state.setPolygonConfig(dialog.config());
        state.selectTool(kToolStamp);
        m_param_widget.setTool(kToolStamp);
    }
}

void MainWindow::askFilename() {
    QString selected_filter;
    QString file_name = QFileDialog::getSaveFileName(
        //
        this, tr("Save Image"), QDir::homePath(),
        tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"),
        &selected_filter, QFileDialog::DontUseNativeDialog);
    qDebug() << selected_filter << "|";
    m_format = selected_filter.split(" ").at(0).toStdString();
    if (!file_name.isEmpty()) {
        m_filename = file_name.toStdString();
    }
}

void MainWindow::saveImage() {
    if (m_filename == "") {
        askFilename();
    }
    if (m_filename != "") {
        auto pixmap = m_canvas.pixmap();
        QString filename = QString::fromStdString(m_filename + "." + m_format);
        if (!pixmap.save(filename, m_format.c_str())) {
            QMessageBox::warning(this, tr("Save Error"),
                                 tr("Failed to save the image."));
        }
    }
}

void MainWindow::saveImageAs() {
    askFilename();
    saveImage();
}

void MainWindow::openImage() {
    auto file_name = QFileDialog::getOpenFileName(
        this, tr("Open Image"), QDir::homePath(),
        tr("Image Files (*.png *.jpg *.bmp)"), nullptr,
        QFileDialog::DontUseNativeDialog);  //works
    m_filename = file_name.toStdString();
    this->setWindowTitle("ICGPaint [" + file_name + "]");
    if (!file_name.isEmpty()) {
        QPixmap loaded_pixmap;
        if (!loaded_pixmap.load(file_name)) {
            QMessageBox::warning(this, tr("Open Error"),
                                 tr("Failed to open the image."));
        } else {
            m_canvas.setPixmap(loaded_pixmap);
        }
    }
}

void MainWindow::resizeCanvas() {
    qDebug() << "resize event";
    auto& state = StateSingleton::instance();
    auto rd = ResizeDialog(this);
    if (rd.exec() == QDialog::Accepted) {
        state.setGeometry(rd.width(), rd.height());
        m_canvas.resize(state.width(), state.height());
    }
}

void MainWindow::aboutSlots() {
    auto about_dialog = AboutDialog(this);
    about_dialog.exec();
}

void MainWindow::helpSlots() {
    auto help_dialog = HelpDialog(this);
    help_dialog.exec();
}
