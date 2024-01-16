#ifndef MEAN_VALUE_FILTER_H
#define MEAN_VALUE_FILTER_H
#include <Filter.h>

    class MeanValueFilter : public Filter {
        public:
            MeanValueFilter();
            void reset() override;
            void addValue(float newValue) override;
            float getFilteredValue() override;
        private:
            unsigned int numValues;
            float sum;
    };
#endif
