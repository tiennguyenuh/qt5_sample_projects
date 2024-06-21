// lightcontroller.cpp

#include "lightcontroller.h"
#include <QDebug>

LightController::LightController(QObject *parent) : QObject(parent)
{
}

#include <QDebug>
#include <cstdio>
#include <cstring>

void LightController::handleValueChanged(int value)
{
    qDebug() << "Value changed in LightController:" << value;

    // Path to the sysfs files
    const char* duty_cycle_path = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle";

    // Convert the integer value to a string
    char str_value[20];

    // Write value to duty_cycle
    FILE* sysfs_handler = fopen(duty_cycle_path, "w");
    if (sysfs_handler == nullptr) {
        qDebug() << "Failed to open" << duty_cycle_path << "for writing";
    } else {

        if(value < 10)
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(10));
        else if(value <= 20)
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(20));
        else if(value <= 30)
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(40));
        else if(value <= 40)
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(60));
        else if(value <= 50)
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(80));
        else
            snprintf(str_value, sizeof(str_value), "%d", BRIGHTNESS(100));

        fwrite(str_value, sizeof(char), 9, sysfs_handler);

        fclose(sysfs_handler);
    }
}

