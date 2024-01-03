#ifndef S_PORT_WRITER_H
#define S_PORT_WRITER_H

#include <Stream.h>

class SPortWriter {
    public:
        SPortWriter(Stream *pStream);
        void write(unsigned char byte);
    private:
        Stream *pStream;    
};

#endif