#include "sensor_data_parse.h"
#include <QDebug>

// Constructor
SensorData::SensorData(QObject *parent) : QObject(parent) {
    // Initialize sensor data to default values if necessary
    hs3001_data.temperature = 28.3f;
    hs3001_data.humidity = 58.1f;

    icm_motion_data.acc_x = 0;
    icm_motion_data.acc_y = 0;
    icm_motion_data.acc_z = 0;
    icm_motion_data.gyr_x = 0;
    icm_motion_data.gyr_y = 0;
    icm_motion_data.gyr_z = 0;
    icm_motion_data.mag_x = 0;
    icm_motion_data.mag_y = 0;
    icm_motion_data.mag_z = 0;
}

// Getter for HS3001 data
hs3001_t SensorData::getHS3001Data() const {
    return hs3001_data;
}

// Getter for ICM motion data
icm_motion_t SensorData::getICMMotionData() const {
    return icm_motion_data;
}

float SensorData::getTemperature()
{
    return this->getHS3001Data().temperature;
}

float SensorData::getHumdiity()
{
    return this->getHS3001Data().humidity;
}
// Setter for HS3001 data
void SensorData::setHS3001Data(float temperature, float humidity) {
    hs3001_data.temperature = (temperature - 32)/1.8;
    hs3001_data.humidity = humidity;
}

// Setter for ICM motion data
void SensorData::setICMMotionData(int acc_x, int acc_y, int acc_z,
                                  int gyr_x, int gyr_y, int gyr_z,
                                  int mag_x, int mag_y, int mag_z) {
    icm_motion_data.acc_x = acc_x;
    icm_motion_data.acc_y = acc_y;
    icm_motion_data.acc_z = acc_z;
    icm_motion_data.gyr_x = gyr_x;
    icm_motion_data.gyr_y = gyr_y;
    icm_motion_data.gyr_z = gyr_z;
    icm_motion_data.mag_x = mag_x;
    icm_motion_data.mag_y = mag_y;
    icm_motion_data.mag_z = mag_z;
}
