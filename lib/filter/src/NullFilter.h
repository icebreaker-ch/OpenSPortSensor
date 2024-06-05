#ifndef NULL_FILTER_H
#define NULL_FILTER_H
#include <Filter.h>

class NullFilter : public Filter {
    public:
        NullFilter();
        void reset() override;
        void addValue(double newValue) override;
        double getFilteredValue() override;

    private:
        double value;
};
#endif
