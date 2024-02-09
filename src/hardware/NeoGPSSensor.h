#ifndef NEO_GPS_SENSOR_H
#define NEO_GPS_SENSOR_H

#include <Arduino.h>
#include <TinyGPS++.h>
#include "IGPSSensor.h"
#include "IPollingDevice.h"

class NeoGPSSensor : public IGPSSensor, public IPollingDevice {
    public:
        NeoGPSSensor();
        void poll() override;
        double getLongitude() override;
        double getLatitude() override;
        double getAltitude() override;
        double getSpeed() override;
        double getCourse() override;

    private:
        TinyGPSPlus gps;
};

#endif