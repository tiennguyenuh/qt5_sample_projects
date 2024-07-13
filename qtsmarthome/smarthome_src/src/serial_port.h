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

public slots:
    float getTemperature();
    float getHumidity();

private slots:
    void connect(QString portName);
    void readSerial();

private:
    QSerialPort *serial;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    float temperature_value;
    float humidity_value;

};

#endif // SERIAL_PORT_H
