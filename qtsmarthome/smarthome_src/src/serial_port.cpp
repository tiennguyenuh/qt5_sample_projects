#include "serial_port.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    temperature_value = 0.0;

    this->connect("/dev/ttySC0");

    /*
     *  Open and check if the port is connected
     */
    if (serial->isOpen())
    {
         qDebug() << "Serial Port Is Connected.";
         qDebug() << serial->error();
    }
    else
    {
        qDebug() << "Serial Port Is Not Connected.";
        qDebug() << serial->error();
    }

    QObject::connect(serial, SIGNAL(readyRead()), this, SLOT(readSerial()));
}

SerialPort::~SerialPort()
{
    if(serial->isOpen()){
        serial->close(); //    Close the serial port if it's open.
    }
}

void SerialPort::connect(QString portName)
{
    serial->setPortName(portName);
    serial->open(QSerialPort::ReadOnly);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);

}
void SerialPort::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     * The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature and humidity values.
     *
     */
    serialData = serial->readAll();
    serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());

    qDebug() << "New data has come";
    qDebug() << serialBuffer;
    serialData.clear();

    // Check if we have a complete message
    QStringList buffer_split = serialBuffer.split(","); // Split the serialBuffer string using ',' as the separator

    // Check if there are at least 2 elements (temp and humidity values)
    if (buffer_split.length() >= 2) {
        QStringList data_split = buffer_split[1].split("\n"); // Split the second part using newline as the separator

        // Ensure we have valid data before updating
        if (data_split.length() >= 2) {
            serialBuffer = "";
            QString temp_str = buffer_split[0];
            QString humi_str = data_split[0];

            bool temp_ok, humi_ok;
            double temp = temp_str.toDouble(&temp_ok);
            double humi = humi_str.toDouble(&humi_ok);

            if (temp_ok && humi_ok) {
                qDebug() << "Temperature: " << temp << ", Humidity: " << humi << "\n";
                this->temperature_value = temp;
                this->humidity_value = humi;
//                Dialog::updateTemperature(temp_str);
//                Dialog::updateHumidity(humi_str); // Assuming you have a similar function for updating humidity
            }
        } else {
            // Incomplete data, keep buffering
            return;
        }
    }
}

float SerialPort::getTemperature()
{
    return this->temperature_value;
}

float SerialPort::getHumidity()
{
    return this->humidity_value;
}