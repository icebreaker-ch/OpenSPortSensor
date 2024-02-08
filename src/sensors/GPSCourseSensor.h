#ifndef GPS_COURSE_SENSOR_H
#define GPS_COURSE_SENSOR_H

#include "global.h"
#include "IGPSSensor.h"
#include "Sensor.h"

/**
 * This sensor reports GPS Course.
*/
class GPSCourseSensor : public Sensor {
    public:
        explicit GPSCourseSensor(IGPSSensor *pGPSSensor, unsigned int sensorId = GPS_COURS_FIRST_ID+ 1);
        long getValue() override;

    private:
        const unsigned int PRECICION = 100; // 2 Digits
        IGPSSensor *pGPSSensor;
};

#endif