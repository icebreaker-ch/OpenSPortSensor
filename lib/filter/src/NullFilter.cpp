#include "NullFilter.h"

NullFilter::NullFilter() :
    value(0.0) {
}

void NullFilter::reset() {
    value = 0.0;
}

void NullFilter::addValue(double newValue) {
    value = newValue;
}

double NullFilter::getFilteredValue() {
    return value;
}
