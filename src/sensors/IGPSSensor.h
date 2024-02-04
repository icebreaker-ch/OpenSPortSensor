#ifndef IGPS_SENSOR_H
#define IGPS_SENSOR_H

class IGPSSensor {
    public:
        virtual float getLongitude() = 0;
        virtual float getLatitude() = 0;
        virtual float getAltitude() = 0;
};

#endif