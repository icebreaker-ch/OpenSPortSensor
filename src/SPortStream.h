#ifndef S_PORT_STREAM_H
#define S_PORT_STREAM_H

#include <Arduino.h>
#include <SoftwareSerial.h>

    /**
     * @brief
     * The class SPortStream makes an abstraction for SoftwareSerial and HardwareSerial streams.
     * @details
     * SoftwareSerial and HardwareSerial are both derived from Stream and therefore can be
     * used in much the same way. This class elliminates some differences in usage.
     * @author
     * Roland Schäuble
    */
    class SPortStream : public Stream {
        public:
            explicit SPortStream(Stream *pSerial);            
            explicit SPortStream(int pin);
            void begin(unsigned long speed, byte config);
            void listen();
            void stopListening();
            virtual int available() override;
            virtual int read() override;
            virtual size_t write(uint8_t) override;
            virtual int peek() override;

        private:
            SPortStream(SPortStream &) = delete;
            SPortStream operator=(SPortStream &) = delete;
            bool isSoftwareStream;
            int pin;
            Stream *pStream;
    };
#endif
