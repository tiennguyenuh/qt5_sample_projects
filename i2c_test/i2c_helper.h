#ifndef I2C_HELPER_H
#define I2C_HELPER_H

#include <QObject>
#define I2C_DEVICE_FILE "dev/i2c-3"
#define I2C_DEVICE_ADDR 0x50

class I2C_Helper : public QObject
{
    Q_OBJECT
public:    
    explicit I2C_Helper(QObject *parent = nullptr);
    ~I2C_Helper();

    int file;
    Q_INVOKABLE int i2c_open();
    Q_INVOKABLE int i2c_write();
    Q_INVOKABLE int i2c_read(int base_address, int next_byte);
    Q_INVOKABLE int i2c_close();

signals:

};

#endif // I2C_HELPER_H
