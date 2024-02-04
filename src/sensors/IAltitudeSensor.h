#ifndef IALTITUDE_SENSOR_H
#define IALTITUDE_SENSOR_H

class IAltitudeSensor {
    public:
        virtual float readAltitude() = 0;
};

#endif