#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ledStatus = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap ledOn("assets/led_on.png");
    QPixmap ledOff("assets/led_off.png");

    FILE* sysfs_handler;
    static char ledStatus_str[2];

    if ( (sysfs_handler = fopen("/sys/class/gpio/P0_0/value", "w")) != NULL ) {
        MainWindow::ledStatus ^= 1;

        sprintf(ledStatus_str, "%d", MainWindow::ledStatus);

        fwrite(ledStatus_str, sizeof(char), 4, sysfs_handler);

        if (MainWindow::ledStatus)
        {
            ui->pic_label->setPixmap(ledOn.scaled(100,100,Qt::KeepAspectRatio));
            ui->ledstatus_text->setText("The led is actived");
        } else
        {
            ui->pic_label->setPixmap(ledOff.scaled(100,100,Qt::KeepAspectRatio));
            ui->ledstatus_text->setText("The led is turned off");
        }

        ui->pic_label->setAlignment(Qt::AlignCenter);
        ui->ledstatus_text->setAlignment(Qt::AlignCenter);

        fclose(sysfs_handler);
    }
}
