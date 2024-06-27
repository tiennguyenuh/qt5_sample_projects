#include "i2c_helper.h"

#include <QDebug>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

I2C_Helper::I2C_Helper(QObject *parent) : QObject(parent)
{
}

I2C_Helper::~I2C_Helper()
{
    this->i2c_close();
}

int I2C_Helper::i2c_open()
{
    QString filename = I2C_DEVICE_FILE;
    this->file = open(filename.toStdString().c_str(), O_RDWR);
    if (this->file < 0) {
        qWarning() << "Failed to open the i2c bus";
        return -1;
    }

    if (ioctl(this->file, I2C_SLAVE, I2C_DEVICE_ADDR) < 0) {
        qWarning() << "Failed to acquire bus access and/or talk to slave";
        return -1;
    }

    return 1;
}

int I2C_Helper::i2c_read(int base_address, int next_byte)
{
    char buf[1] = { static_cast<char>(base_address) };

    if (::write(this->file, buf, 1) != 1) {
        qWarning() << "Failed to write to the i2c bus";
        return -1;
    }

    char data[1] = { 0 };
    if (::read(this->file, data, next_byte) != 1) {
        qWarning() << "Failed to read from the i2c bus";
        return -1;
    }

    qDebug() << "Data read:" << QString::number(static_cast<unsigned char>(data[0]), 16);
    return 1;
}

int I2C_Helper::i2c_write()
{
    return 1;
}

int I2C_Helper::i2c_close()
{
    if (this->file != -1) {
        close(this->file);
        this->file = -1;
    }

    return 1;
}
