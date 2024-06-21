#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlContext>
#include "lightcontroller.h"
#include "myquickview.h"

int pwm_init()
{
    FILE* sysfs_handler;

    /* Open pwm0 file */
    if ( (sysfs_handler = fopen("/sys/class/pwm/pwmchip0/export", "w")) != NULL ) {
        fwrite("0", sizeof(char), 2, sysfs_handler);

        if ( (sysfs_handler = fopen("/sys/class/pwm/pwmchip0/pwm0/period", "w")) != NULL ) {
            fwrite("20000000", sizeof(char), 9, sysfs_handler);
            fclose(sysfs_handler);
            return 1;
        }
    }

    fclose(sysfs_handler);
    return 0;
}
Q_DECL_EXPORT int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    LightController lightController;

    MyQuickView viewer;
    //viewer.setOrientation(QQuickView::ScreenOrientationAuto);
    viewer.setSource(QUrl("qml/smarthome/smarthome.qml"));

    viewer.rootContext()->setContextProperty("lightController", &lightController);

    QObject::connect((QObject*)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    viewer.resize(800, 480);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);

    pwm_init();
    viewer.show();

    return app.exec();
}
