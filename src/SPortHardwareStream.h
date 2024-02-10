#ifndef S_PORT_HARDWARE_STREAM_H
#define S_PORT_HARDWARE_STREAM_H

#include "config.h"
#ifdef USE_HARDWARE_SERIAL

#include <Arduino.h>
#include "ISPortStream.h"

/**
 * Implementation of the ISPortStream interface using HardwwareSerial.
*/
class SPortHardwareStream : public ISPortStream {
    public:
        explicit SPortHardwareStream(HardwareSerial *pStream);
        virtual void begin(unsigned long speed, byte config);
        virtual void listen();
        virtual void stopListening();
        virtual int available() override;
        virtual int read() override;
        virtual size_t write(uint8_t) override;
        virtual int peek() override;

    private:
        int pin;
        HardwareSerial *pStream;
};
#endif

#endif