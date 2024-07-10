#include "mainwindow.h"
#include "i2c_helper.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    // Create an instance of I2C_Helper
    I2C_Helper i2cHelper;

    // Open the I2C bus
//    if (i2cHelper.i2c_open(I2C_DEVICE_FILE, I2C_DEVICE_ADDR) < 0) {
//        qWarning() << "Failed to open I2C bus";
//        return 1;
//    }

//    // Read from the I2C device
//    QByteArray data;
//    data.append(0x32); // Example data

//    if (i2cHelper.i2c_write(0x01, data) < 0) {
//        qWarning() << "Failed to read from I2C device";
//        return 1;
//    }

//    // Close the I2C bus (optional, depending on your application flow)
//    i2cHelper.i2c_close();
    w.show();
    return a.exec();
}
