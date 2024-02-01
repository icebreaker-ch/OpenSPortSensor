#include <Arduino.h>
#include "Timer.h"

Timer::Timer(unsigned long milliSeconds) :
    milliSeconds(milliSeconds) {
        lastElapsed = millis(); // starting now
}

bool Timer::isElapsed() {
    unsigned long current = millis();
    bool elapsed = false;
    if ((current - lastElapsed) >= milliSeconds) {
        elapsed = true;
        lastElapsed = current;
    }
    return elapsed;
}

unsigned long Timer::getMillisSinceLast() {
    return millis() - lastElapsed;
}
