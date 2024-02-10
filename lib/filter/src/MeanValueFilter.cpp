#include "MeanValueFilter.h"

MeanValueFilter::MeanValueFilter() :
    numValues(0),
    sum(0.0F) {
}

void MeanValueFilter::reset() {
    numValues = 0;
    sum = 0.0F;
}

void MeanValueFilter::addValue(float newValue) {
    sum += newValue;
    ++numValues;
}

float MeanValueFilter::getFilteredValue() {
    return numValues > 0 ? sum / numValues : 0.0F;
}
