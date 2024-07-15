#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlContext>
#include "lightcontroller.h"
#include "myquickview.h"
#include "serial_port.h"
#include <QProcess>

void startBackgroundProcess()
{
    QString program = "/home/root/qt/serial/serial.sh";
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

Q_DECL_EXPORT int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    LightController lightController;
    // SerialPort serialPort;
    startBackgroundProcess();
    MyQuickView viewer;
    //viewer.setOrientation(QQuickView::ScreenOrientationAuto);
    viewer.setSource(QUrl("qml/smarthome/smarthome.qml"));

    viewer.rootContext()->setContextProperty("lightController", &lightController);
//    viewer.rootContext()->setContextProperty("serialPort", &serialPort);

    QObject::connect((QObject*)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    viewer.resize(800, 480);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);

    // pwm_init();
    viewer.show();

    return app.exec();
}
