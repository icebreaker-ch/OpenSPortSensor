#include <Arduino.h>
#include "Interval.h"

Interval::Interval(unsigned long milliSeconds) :
    milliSeconds(milliSeconds) {
        lastElapsed = millis(); // starting now
}

bool Interval::isElapsed() {
    unsigned long current = millis();
    bool elapsed = false;
    if ((current - lastElapsed) >= milliSeconds) {
        elapsed = true;
        lastElapsed = current;
    }
    return elapsed;
}
