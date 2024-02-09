#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

// #define LOGGING_ON

#ifdef LOGGING_ON
extern void printLog();

template <class T, class... Types>
void printLog(T firstArg, Types... args) {
    Serial.print(firstArg); // printing first argument
    printLog(args...);      // printing the rest of the arguments recursive
}

    #define LOG(...) printLog(__FILE__, ":", __LINE__, ": ", __VA_ARGS__)
#else
    #define LOG(...)
#endif

#endif