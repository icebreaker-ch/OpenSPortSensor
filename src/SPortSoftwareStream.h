#ifndef S_PORT_SOFTWARE_STREAM_H
#define S_PORT_SOFTWARE_STREAM_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "ISPortStream.h"

/**
 * Implementation of the ISPortStream interface using SoftwareSerial.
*/
class SPortSoftwareStream : public ISPortStream {
    public:
        explicit SPortSoftwareStream(int pin);
        virtual void begin(unsigned long speed, byte config) override;
        virtual void listen() override;
        virtual void stopListening() override;
        virtual int available() override;
        virtual int read() override;
        virtual size_t write(uint8_t) override;
        virtual int peek() override;

    private:
        int pin;
        SoftwareSerial serial;
};

#endif