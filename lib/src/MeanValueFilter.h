#ifndef MEAN_VALUE_FILTER_H
#define MEAN_VALUE_FILTER_H
#include <Filter.h>

    class MeanValueFilter : public Filter {
        public:
            MeanValueFilter(unsigned int maxValues);
            void reset();
            void addValue(float newValue);
            unsigned int getNumValues();
            float getFilteredValue();
        private:
            unsigned int index;
            unsigned int maxValues;
            unsigned int numValues;
            float *pValues;
    };
#endif
