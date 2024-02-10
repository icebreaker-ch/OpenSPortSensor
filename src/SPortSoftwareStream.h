#ifndef S_PORT_SOFTWARE_STREAM_H
#define S_PORT_SOFTWARE_STREAM_H

#include "config.h"

#ifndef USE_HARDWARE_SERIAL

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "ISPortStream.h"

/**
 * Implementation of the ISPortStream interface using SoftwareSerial.
*/
class SPortSoftwareStream : public ISPortStream {
    public:
        explicit SPortSoftwareStream(int pin);
        virtual void begin(unsigned long speed, byte config);
        virtual void listen();
        virtual void stopListening();
        virtual int available() override;
        virtual int read() override;
        virtual size_t write(uint8_t) override;
        virtual int peek() override;

    private:
        int pin;
        SoftwareSerial *pStream;
};

#endif

#endif