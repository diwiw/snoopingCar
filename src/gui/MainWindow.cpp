#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // This sets up the UI as defined in the .ui file

    // Connect the button's clicked signal to the appropriate slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Implementation of the slot for the button click
void MainWindow::on_pushButton_clicked()
{
    // Action to be taken when the button is clicked
    qDebug("Button clicked!");
}
