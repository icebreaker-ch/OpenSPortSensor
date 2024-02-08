#ifndef IGPS_SENSOR_H
#define IGPS_SENSOR_H

class IGPSSensor {
    public:
        virtual double getLongitude() = 0;
        virtual double getLatitude() = 0;
        virtual double getAltitude() = 0;
        virtual double getSpeed() = 0;
};

#endif