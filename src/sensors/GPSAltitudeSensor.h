#ifndef GPS_ALTITUDE_SENSOR_H
#define GPS_ALTITUDE_SENSOR_H

#include "global.h"
#include "IGPSSensor.h"
#include "Sensor.h"

/**
 * This sensor reports GPS Altitude.
 */
class GPSAltitudeSensor : public Sensor {
    public:
        explicit GPSAltitudeSensor(IGPSSensor *pGPSSensor, unsigned int sensorId = GPS_ALT_FIRST_ID + 1);
        long getValue() override;

    private:
        static const unsigned int PRECICION = 100; // 2 Digits
        static const unsigned int DEFAULT_TIMEOUT = 10000U;
        IGPSSensor *pGPSSensor;
};

#endif