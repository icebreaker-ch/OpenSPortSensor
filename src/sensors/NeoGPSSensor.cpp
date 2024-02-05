#include "NeoGPSSensor.h"

NeoGPSSensor::NeoGPSSensor() {
    Serial1.begin(9600, SERIAL_8N1);
}

void NeoGPSSensor::poll() {
    while (Serial1.available() > 0) {
        char c = Serial1.read();
        gps.encode(c);
     }
}

double NeoGPSSensor::getLongitude() {
    return gps.location.isValid() ? gps.location.lng() : 0;
}

double NeoGPSSensor::getLatitude() {
    return gps.location.isValid() ? gps.location.lat() : 0;
}

double NeoGPSSensor::getAltitude() {
    return gps.altitude.isValid() ?  gps.altitude.meters() : 0;
}
