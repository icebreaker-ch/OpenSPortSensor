#ifndef ISPORT_STREAM_H
#define ISPORT_STREAM_H

#include <Arduino.h>

class ISPortStream : public Stream {
    public:
        virtual void begin(unsigned long speed, byte config) = 0;
        virtual void listen() = 0;
        virtual void stopListening() = 0;
        virtual int available() override = 0;
        virtual int read() override = 0;
        virtual size_t write(uint8_t) override = 0;
        virtual int peek() override = 0;
};

#endif