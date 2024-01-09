#include <assert.h>
#include <Arduino.h>
#include "MeanValueFilter.h"

MeanValueFilter::MeanValueFilter(unsigned int maxValues) :
    index(0),
    maxValues(maxValues),
    numValues(0) {
        pValues = new float[maxValues];
}

void MeanValueFilter::addValue(float newValue) {
    index = (index + 1) % maxValues;
        pValues[index] = newValue;
    numValues = min(numValues + 1, maxValues);
}

bool MeanValueFilter::isFilteredValueAvailable()
{
    return numValues >= 0;
}

float MeanValueFilter::getFilteredValue() {
    assert(numValues > 0);

    float sum = 0;
    for (int i = 0; i < numValues; ++i) {
        sum += pValues[i];
    }
    numValues = 0;
    index = 0;
    return sum / (float)numValues;
}
