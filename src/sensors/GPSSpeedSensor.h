#ifndef GPS_SPEED_SENSOR_H
#define GPS_SPEED_SENSOR_H

#include "global.h"
#include "IGPSSensor.h"
#include "Sensor.h"

/**
 * This sensor reports GPS Speed.
*/
class GPSSpeedSensor : public Sensor {
    public:
        explicit GPSSpeedSensor(IGPSSensor *pGPSSensor, unsigned int sensorId = GPS_SPEED_FIRST_ID + 1);
        long getValue() override;

    private:
        const unsigned int PRECICION = 100; // 2 Digits
        IGPSSensor *pGPSSensor;
};

#endif