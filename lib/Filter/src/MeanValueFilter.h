#ifndef MEAN_VALUE_FILTER_H
#define MEAN_VALUE_FILTER_H
#include <Filter.h>

    class MeanValueFilter : public Filter {
        public:
            MeanValueFilter();
            void reset();
            void addValue(float newValue);
            float getFilteredValue();
        private:
            unsigned int numValues;
            float sum;
    };
#endif
