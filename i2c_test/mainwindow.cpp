#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "i2c_helper.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Test";

    I2C_Helper i2cHelper;

    // Open the I2C bus
    if (i2cHelper.i2c_open() < 0) {
        qWarning() << "Failed to open I2C bus";
        return;
    }

    // Read from the I2C device
    if (i2cHelper.i2c_read(0x01, 1) < 0) {
        qWarning() << "Failed to read from I2C device";
        return;
    }

    qDebug() << "Test";
}
