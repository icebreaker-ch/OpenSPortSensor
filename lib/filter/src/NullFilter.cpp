#include "NullFilter.h"

NullFilter::NullFilter() :
   value(0.0F) {
}

void NullFilter::reset()
{
    value = 0.0F;
}

void NullFilter::addValue(float newValue) {
    value = newValue;
}

float NullFilter::getFilteredValue() {
    return value;
}
