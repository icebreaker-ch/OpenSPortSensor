#ifndef MEAN_VALUE_FILTER_H
#define MEAN_VALUE_FILTER_H
#include <Filter.h>

class MeanValueFilter : public Filter {
    public:
        MeanValueFilter();
        void reset() override;
        void addValue(double newValue) override;
        double getFilteredValue() override;

    private:
        unsigned int numValues;
        double sum;
};
#endif
