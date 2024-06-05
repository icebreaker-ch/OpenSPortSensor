#include "MeanValueFilter.h"

MeanValueFilter::MeanValueFilter() :
    numValues(0),
    sum(0.0) {
}

void MeanValueFilter::reset() {
    numValues = 0;
    sum = 0.0;
}

void MeanValueFilter::addValue(double newValue) {
    sum += newValue;
    ++numValues;
}

double MeanValueFilter::getFilteredValue() {
    return numValues > 0 ? sum / numValues : 0.0;
}
