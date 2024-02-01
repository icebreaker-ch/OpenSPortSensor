#ifndef INTERVAL_H
#define INTERVAL_H

class Timer {
    public:
        Timer();
        void reset();
        unsigned long getElapsedTime();

    private:
        unsigned long startMillis;
};

#endif