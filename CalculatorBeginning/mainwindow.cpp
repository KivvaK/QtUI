#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reset();

    connect(
        ui->pb1, &QPushButton::clicked,
        this, &MainWindow::on_number_input
        );
    connect(
        ui->pb2, &QPushButton::clicked,
        this, &MainWindow::on_number_input
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_number_input() {
    QPushButton* pb = dynamic_cast<QPushButton*>(sender());
    QString digit = pb->text();

    if (state == State::FirstDigit) {
        ui->leInput->setText("");
        if (digit != "0")
            state = State::InputNumber;
    }
    ui->leInput->setText(ui->leInput->text() + digit);
}

void MainWindow::reset() {
    ui->leInput->setText("0");
    state = State::FirstDigit;
}
