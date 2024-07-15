#ifndef SENSOR_DATA_PARSE_H
#define SENSOR_DATA_PARSE_H

#include <QObject>

struct hs3001_t {
    float temperature;
    float humidity;
};

struct icm_motion_t {
    /* Accelerometer: Measures acceleration along the X, Y, and Z axes */
    int acc_x;
    int acc_y;
    int acc_z;

    /* Gyroscope: Measures angular velocity along the X, Y, and Z axes */
    int gyr_x;
    int gyr_y;
    int gyr_z;

    /* Magnetometer: Measures the magnetic field along the X, Y, and Z axes */
    int mag_x;
    int mag_y;
    int mag_z;
};

class SensorData : public QObject {
    Q_OBJECT
public:
    SensorData(QObject *parent = nullptr);

    Q_INVOKABLE void setHS3001Data(float temperature, float humidity);
    Q_INVOKABLE void setICMMotionData(int acc_x, int acc_y, int acc_z,
                          int gyr_x, int gyr_y, int gyr_z,
                          int mag_x, int mag_y, int mag_z);

    hs3001_t getHS3001Data() const;
    icm_motion_t getICMMotionData() const;

    Q_INVOKABLE float getTemperature();
    Q_INVOKABLE float getHumdiity();

private:
    hs3001_t hs3001_data;
    icm_motion_t icm_motion_data;
};

#endif // SENSOR_DATA_PARSE_H
