#include "colorpicker.hpp"

#include <qlogging.h>
#include <QColor>

#include <QColorDialog>

#include "ui_colorpicker.h"

#include <QWidget>

#include "../common/state.hpp"

const int kUsualSize = 20;
const int kSelectedSize = 30;

ColorPicker::ColorPicker(QWidget* parent)
    : QWidget(parent),
      m_ui(new Ui::ColorPicker),
      m_current_color_id(0),
      m_buttons(9) {
    m_ui->setupUi(this);
    m_buttons[0] = m_ui->btnBlack;
    m_buttons[1] = m_ui->btnRed;
    m_buttons[2] = m_ui->btnYellow;
    m_buttons[3] = m_ui->btnGreen;
    m_buttons[4] = m_ui->btnCyan;
    m_buttons[5] = m_ui->btnBlue;
    m_buttons[6] = m_ui->btnMagenta;
    m_buttons[7] = m_ui->btnWhite;
    m_buttons[8] = m_ui->btnCustom;

    connect(m_ui->btnBlack, &QPushButton::clicked, this,
            &ColorPicker::clickedBlack);

    connect(m_ui->btnRed, &QPushButton::clicked, this,
            &ColorPicker::clickedRed);

    connect(m_ui->btnYellow, &QPushButton::clicked, this,
            &ColorPicker::clickedYellow);

    connect(m_ui->btnGreen, &QPushButton::clicked, this,
            &ColorPicker::clickedGreen);

    connect(m_ui->btnCyan, &QPushButton::clicked, this,
            &ColorPicker::clickedCyan);

    connect(m_ui->btnBlue, &QPushButton::clicked, this,
            &ColorPicker::clickedBlue);

    connect(m_ui->btnMagenta, &QPushButton::clicked, this,
            &ColorPicker::clickedMagenta);

    connect(m_ui->btnRed, &QPushButton::clicked, this,
            &ColorPicker::clickedRed);

    connect(m_ui->btnWhite, &QPushButton::clicked, this,
            &ColorPicker::clickedWhite);

    connect(m_ui->btnCustom, &QPushButton::clicked, this,
            &ColorPicker::clickedCustom);

    highlight();
}

ColorPicker::~ColorPicker() {
    delete m_ui;
}

void ColorPicker::setColor(int colorId, QColor color) {
    auto& state = StateSingleton::instance();
    state.setColor(color);
    m_current_color_id = colorId;
    highlight();
}

void ColorPicker::styleButton(QPushButton* btn, const QColor& color) {
    btn->setStyleSheet(QString("background-color: %1; border: 1px solid black")
                           .arg(color.name()));
}

void ColorPicker::highlight() {
    auto state_color = StateSingleton::instance().color();
    for (int i = 0; i < m_colors.size(); ++i) {
        ColorPicker::styleButton(m_buttons[i], m_colors[i]);
    }
    ColorPicker::styleButton(m_ui->btnCustom, state_color);

    m_buttons[m_current_color_id]->setStyleSheet(
        QString("background-color: %1; border: 3px solid %2;")
            .arg(state_color.name(), m_current_color_id == 0
                                         ? QColorConstants::Green.name()
                                         : QColorConstants::Black.name()));
}

void ColorPicker::clickedBlack() {
    setColor(0, QColorConstants::Black);
}

void ColorPicker::clickedRed() {
    setColor(1, QColorConstants::Red);
}

void ColorPicker::clickedYellow() {
    setColor(2, QColorConstants::Yellow);
}

void ColorPicker::clickedGreen() {
    setColor(3, QColorConstants::Green);
}

void ColorPicker::clickedCyan() {
    setColor(4, QColorConstants::Cyan);
}

void ColorPicker::clickedBlue() {
    setColor(5, QColorConstants::Blue);
}

void ColorPicker::clickedMagenta() {
    setColor(6, QColorConstants::Magenta);
}

void ColorPicker::clickedWhite() {
    setColor(7, QColorConstants::White);
}

void ColorPicker::clickedCustom() {
    auto& state = StateSingleton::instance();
    QColor color = QColorDialog::getColor(state.color(), this, "Выберите цвет");
    setColor(8, color);
}
