#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlContext>
#include <QProcess>
#include "myquickview.h"
#include "lightcontroller.h"
#include "serial_port.h"
#include "file_reader.h"
#include "sensor_data_parse.h"

void startBackgroundProcess(QString filePath)
{
    QString program = filePath;
    QStringList arguments; // Optional arguments to pass to your script

    QProcess *process = new QProcess();
    process->start(program, arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Error starting process:" << process->errorString();
        return;
    }

    qDebug() << "Process started successfully. PID:" << process->processId();
}

int pwm_init()
{
    FILE* sysfs_handler;

    // Open pwm0 file
    sysfs_handler = fopen("/sys/class/pwm/pwmchip1/export", "w");
    if (sysfs_handler != NULL) {
        fwrite("0", sizeof(char), 2, sysfs_handler);
        fclose(sysfs_handler); // Close after writing

        // Open the period file
        sysfs_handler = fopen("/sys/class/pwm/pwmchip1/pwm0/period", "w");
        if (sysfs_handler != NULL) {
            fwrite("20000000", sizeof(char), 9, sysfs_handler);
            fclose(sysfs_handler);
        } else {
            // Handle error for opening period file
            perror("Failed to open period file");
        }

        sysfs_handler = fopen("/sys/class/pwm/pwmchip1/pwm0/enable", "w");
        if (sysfs_handler != NULL) {
            fwrite("1", sizeof(char), 2, sysfs_handler);
            fclose(sysfs_handler);
            return 1; // Success
        } else {
            // Handle error for opening period file
            perror("Failed to open period file");
        }
    } else {
        // Handle error for opening export file
        perror("Failed to open export file");
    }

    // If any fopen failed, return 0
    return 0;
}

void handleFileUpdate(const QString &content, SensorData *sensorData)
{
    // Split the content by newline character
    QStringList lines = content.split('\n', QString::SkipEmptyParts);

    // Print the split lines for debugging
    qDebug() << "Handling file update:";
    if (!lines.isEmpty())
    {
        // Parse temperature which is the first line of filePath
        QString hs3001_str = lines.first();
        qDebug() << "First line data: " << hs3001_str;
        QStringList hs3001_str_split = hs3001_str.split(',');

        QString icm_str = lines.at(1);
        qDebug() << "Second line data: " << icm_str;
        QStringList icm_str_split = icm_str.split(',');

        if (sensorData)
        {
            if (hs3001_str_split.size() >= 2)
            {
                float temperature = hs3001_str_split[0].toFloat();
                float humidity = hs3001_str_split[1].toFloat();
                sensorData->setHS3001Data(temperature, humidity);
            }
            else
            {
                qDebug() << "Error parsing HS3001 data: Not enough elements";
            }

            if (icm_str_split.size() >= 9)
            {
                sensorData->setICMMotionData(icm_str_split[0].toInt(), icm_str_split[1].toInt(), icm_str_split[2].toInt(),
                                             icm_str_split[3].toInt(), icm_str_split[4].toInt(), icm_str_split[5].toInt(),
                                             icm_str_split[6].toInt(), icm_str_split[7].toInt(), icm_str_split[8].toInt());
            }
            else
            {
                qDebug() << "Error parsing ICM motion data: Not enough elements";
            }
        }
        else
        {
            qDebug() << "Null pointer to SensorData!";
            // Handle the error appropriately
        }

    }
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    /* Class */
    LightController lightController;
    // SerialPort serialPort;
    SensorData sensorData;
    // Retrieve and print HS3001 data
    /*hs3001_t hs3001_data*/;

    /* Back ground process and file reader */
    QString filePath = "data.txt";
    startBackgroundProcess(filePath);

    FileReader monitor(filePath);

    QObject::connect(&monitor, &FileReader::fileUpdated, [&sensorData](const QString &content){
        handleFileUpdate(content, &sensorData);
    });

    MyQuickView viewer;
    //viewer.setOrientation(QQuickView::ScreenOrientationAuto);
    viewer.setSource(QUrl("qml/smarthome/smarthome.qml"));

    viewer.rootContext()->setContextProperty("lightController", &lightController);
//    viewer.rootContext()->setContextProperty("serialPort", &serialPort);
    viewer.rootContext()->setContextProperty("sensorData", &sensorData);

    QObject::connect((QObject*)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    viewer.resize(800, 480);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);

    // pwm_init();
    viewer.show();

    return app.exec();
}
