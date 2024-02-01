#include <Arduino.h>
#include "Timer.h"

Timer::Timer() :
    startMillis(millis()) {
}

void Timer::reset() {
    startMillis = millis();
}

unsigned long Timer::getElapsedTime() {
    return millis() - startMillis;
}
