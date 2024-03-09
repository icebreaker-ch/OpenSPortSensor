#ifndef S_PORT_HARDWARE_STREAM_H
#define S_PORT_HARDWARE_STREAM_H

#include "config.h"
#include <Arduino.h>
#include "ISPortStream.h"

/**
 * Implementation of the ISPortStream interface using HardwwareSerial.
*/
class SPortHardwareStream : public ISPortStream {
    public:
        explicit SPortHardwareStream();
        virtual void begin(unsigned long speed, byte config) override;
        virtual void listen() override;
        virtual void stopListening() override;
        virtual int available() override;
        virtual int read() override;
        virtual size_t write(uint8_t) override;
        virtual int peek() override;

    private:
        HardwareSerial &serial;
};

#endif