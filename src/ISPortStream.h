#ifndef ISPORT_STREAM_H
#define ISPORT_STREAM_H

#include <Arduino.h>

class ISPortStream : public Stream {
    public:
        virtual void begin(unsigned long speed, byte config);
        virtual void listen() = 0;
        virtual void stopListening() = 0;
        virtual int available() = 0;
        virtual int read() = 0;
        virtual size_t write(uint8_t) = 0;
        virtual int peek() = 0;
};

#endif