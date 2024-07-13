#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
#include <QObject>

class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();

private slots:
    void readSerial();
    void updateTemperature(QString);

private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    double temperature_value;
};

#endif // SERIAL_PORT_H
