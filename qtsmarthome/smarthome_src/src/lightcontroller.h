// lightcontroller.h

#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <QObject>

#define PWM_PERIOD 20000000
#define BRIGHTNESS(percentage) ( PWM_PERIOD * percentage / 100 )

class LightController : public QObject
{
    Q_OBJECT
public:
    explicit LightController(QObject *parent = nullptr);

    Q_INVOKABLE void handleValueChanged(int value);

signals:

};

#endif // LIGHTCONTROLLER_H
