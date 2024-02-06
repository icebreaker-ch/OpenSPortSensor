#ifndef NEO_GPS_SENSOR_H
#define NEO_GPS_SENSOR_H

#include <Arduino.h>
#include <TinyGPS++.h>
#include "IGPSSensor.h"
#include "IPolling.h"

class NeoGPSSensor : public IGPSSensor, IPolling {
    public:
        NeoGPSSensor();
        void poll() override;
        double getLongitude() override;
        double getLatitude() override;
        double getAltitude() override;
    private:
        TinyGPSPlus gps;
};

#endif