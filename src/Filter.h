#ifndef FILTER_H
#define FILTER_H

/**
 * Abstract class for filtering values by any algorithm.
*/
class Filter {
    public:
        virtual void addValue(float newValue) = 0;
        virtual bool isFilteredValueAvailable() = 0;
        virtual float getFilteredValue() = 0;
        virtual ~Filter() = 0;
};

#endif