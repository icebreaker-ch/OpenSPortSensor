#ifndef SENSOR_H
#define SENSOR_H

/**
 * Base class for all Sensors.
*/
class Sensor {
    public:
        Sensor(int sensorId) :
            sensorId(sensorId) {
        }

        int getSensorId() {
            return sensorId;
        }

        virtual long getValue() = 0;

    private:
        int sensorId;
};
#endif