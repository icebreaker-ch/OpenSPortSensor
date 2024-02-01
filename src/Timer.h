#ifndef TIMER_H
#define TIMER_H

class Timer {
    public:
        Timer();
        void reset();
        unsigned long getElapsedTime();

    private:
        unsigned long startMillis;
};

#endif