#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    FILE* sysfs_handler;

    /* Open LED P0_0 file */
    if ( (sysfs_handler = fopen("/sys/class/gpio/export", "w")) != NULL ) {
        fwrite("120", sizeof(char), 4, sysfs_handler);
        fclose(sysfs_handler);
    }

    /* Set output as direction */
    if ( (sysfs_handler = fopen("/sys/class/gpio/direction", "w")) != NULL ) {
        fwrite("out", sizeof(char), 4, sysfs_handler);
        fclose(sysfs_handler);
    }

    w.show();
    return a.exec();
}
