#ifndef ALTITUDE_SENSOR_H
#define ALTITUDE_SENSOR_H

class IAltitudeSensor {
    public:
        virtual float readAltitude() = 0;
};

#endif