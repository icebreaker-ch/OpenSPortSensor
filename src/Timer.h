#ifndef INTERVAL_H
#define INTERVAL_H

class Timer {
    public:
        explicit Timer(unsigned long milliSeconds);
        bool isElapsed();
        unsigned long getMillisSinceLast();

    private:
        unsigned long lastElapsed;
        unsigned long milliSeconds;
};

#endif