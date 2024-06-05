#ifndef FILTER_H
#define FILTER_H

/**
 * Abstract class for filtering values by any algorithm.
*/
class Filter {
    public:
        virtual void reset() = 0;
        virtual void addValue(double newValue) = 0;
        virtual double getFilteredValue() = 0;
        virtual ~Filter() {}
};

#endif