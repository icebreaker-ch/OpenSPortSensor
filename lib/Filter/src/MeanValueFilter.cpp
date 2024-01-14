#include "MeanValueFilter.h"

#define MIN(a, b) a <= b ? a : b;

MeanValueFilter::MeanValueFilter(unsigned int maxValues) :
    index(0),
    maxValues(maxValues),
    numValues(0) {
        pValues = new float[maxValues];
}

void MeanValueFilter::reset()
{
    numValues = 0;
    index = 0;
}

void MeanValueFilter::addValue(float newValue) {
    pValues[index] = newValue;
    index = (index + 1) % maxValues; // Ringbuffer
    numValues = MIN(numValues + 1, maxValues);
}

unsigned int MeanValueFilter::getNumValues()
{
    return numValues;
}

float MeanValueFilter::getFilteredValue() {
    float mean = 0.0;
    if (numValues > 0) {
        float sum = 0;
         for (unsigned int i = 0; i < numValues; ++i) {
            sum += pValues[i];
         }
        mean = sum / numValues;
    }
    return mean;
}
