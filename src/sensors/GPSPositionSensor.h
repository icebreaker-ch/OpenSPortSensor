#ifndef GPS_POSITION_SENSOR_H
#define GPS_POSITION_SENSOR_H

#include "global.h"
#include "IGPSSensor.h"
#include "Sensor.h"

/**
 * This sensor reports GPS Latitude and Longitude values alternating for each request.
*/
class GPSPositionSensor : public Sensor {
    public:
        explicit GPSPositionSensor(IGPSSensor *pGPSSensor, unsigned int sensorId = GPS_LONG_LATI_FIRST_ID + 1);
        long getValue();

    private:
        bool reportLongitude;
        IGPSSensor *pGPSSensor;
};

#endif