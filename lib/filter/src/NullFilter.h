#ifndef NULL_FILTER_H
#define NULL_FILTER_H
#include <Filter.h>

    class NullFilter : public Filter {
        public:
            NullFilter();
            void reset() override;
            void addValue(float newValue) override;
            float getFilteredValue() override;
        private:
            float value;
    };
#endif
