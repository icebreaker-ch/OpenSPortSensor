#ifndef IPOLLING_DEVICE_H
#define IPOLLING_DEVICE_H

class IPollingDevice {
    public:
        virtual void poll() = 0;
};

#endif