#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
    public:
        explicit Interval(unsigned long milliSeconds);
        bool isElapsed();
        unsigned long getMillisSinceLast();

    private:
        unsigned long lastElapsed;
        unsigned long milliSeconds;
};

#endif