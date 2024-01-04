#ifndef SENSOR_HUB_H
#define SENSOR_HUB_H

#include "Sensor.h"

#define DEFAULT_MAX_SENSORS 10

enum PhysicalId {
    PHYSICAL_ID0 = 0x00, // Physical ID 0 - Vario2 (altimeter high precision)
    PHYSICAL_ID1 = 0xA1, // Physical ID 1 - FLVSS Lipo sensor (can be sent with one or two cell voltages)
    PHYSICAL_ID2 = 0x22, // Physical ID 2 - FAS-40S current sensor
    PHYSICAL_ID3 = 0x83, // Physical ID 3 - GPS / altimeter (normal precision)
    PHYSICAL_ID4 = 0xE4, // Physical ID 4 - RPM
    PHYSICAL_ID5 = 0x45, // Physical ID 5 - SP2UART(Host)
    PHYSICAL_ID6 = 0xC6, // Physical ID 6 - SPUART(Remote)
    PHYSICAL_ID7 = 0x67, // Physical ID 7
    PHYSICAL_ID8 = 0x48, // Physical ID 8
    PHYSICAL_ID9 = 0xE9, // Physical ID 9
    PHYSICAL_ID10 = 0x6A, // Physical ID 10
    PHYSICAL_ID11 = 0xCB, // Physical ID 11
    PHYSICAL_ID12 = 0xAC, // Physical ID 12
    PHYSICAL_ID13 = 0x0D, // Physical ID 13
    PHYSICAL_ID14 = 0x8E, // Physical ID 14
    PHYSICAL_ID15 = 0x2F, // Physical ID 15
    PHYSICAL_ID16 = 0xD0, // Physical ID 16
    PHYSICAL_ID17 = 0x71, // Physical ID 17
    PHYSICAL_ID18 = 0xF2, // Physical ID 18
    PHYSICAL_ID19 = 0x53, // Physical ID 19
    PHYSICAL_ID20 = 0x34, // Physical ID 20
    PHYSICAL_ID21 = 0x95, // Physical ID 21
    PHYSICAL_ID22 = 0x16, // Physical ID 22
    PHYSICAL_ID23 = 0xB7, // Physical ID 23 - IMU ACC (x,y,z)
    PHYSICAL_ID24 = 0x98, // Physical ID 24
    PHYSICAL_ID25 = 0x39, // Physical ID 25 - Power Box
    PHYSICAL_ID26 = 0xBA, // Physical ID 26 - Temp
    PHYSICAL_ID27 = 0x1B // Physical ID 27 - Fuel (ArduPilot/Betaflight)
};

class SensorHub {
    public:
        SensorHub(PhysicalId physicalId, int maxSensorCount = DEFAULT_MAX_SENSORS);
        void addSensor(Sensor *pSensor);
        int getPhysicalId();
        Sensor *getNextSensor();

    private:
        PhysicalId physicalId;
        int sensorCount;
        int currentSensorIndex;
        Sensor **pSensors;
};

#endif