#ifndef SENSOR_H
#define SENSOR_H

/**
 * Base class for all Sensors.
*/
class Sensor {
    public:
        Sensor(unsigned int sensorId) :
            sensorId(sensorId) {
        }

        int getSensorId() {
            return sensorId;
        }

        virtual long getValue() = 0;

    private:
        unsigned int sensorId;
};
#endif