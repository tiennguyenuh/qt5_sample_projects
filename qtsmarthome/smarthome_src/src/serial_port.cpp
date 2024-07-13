#include "serial_port.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    temperature_value = 0.0;

    /*
     *   Identify the port the arduino uno is on.
     */
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        qDebug() << this, "Serial Port Error", "Couldn't open serial port to arduino.";
    }
}

SerialPort::~SerialPort()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
}

void SerialPort::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     * The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature and humidity values.
     *
     */
    serialData = arduino->readAll();
    serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
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
//                Dialog::updateTemperature(temp_str);
//                Dialog::updateHumidity(humi_str); // Assuming you have a similar function for updating humidity
            }
        } else {
            // Incomplete data, keep buffering
            return;
        }
    }
}
void SerialPort::updateTemperature(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    //ui->temp_lcdNumber->display(sensor_reading);
}
