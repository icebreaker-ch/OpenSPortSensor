#include <unity.h>
#include <MeanValueFilter.h>

static MeanValueFilter *pMeanValueFilter;

void setUp(void) {
    pMeanValueFilter = new MeanValueFilter();
}

void tearDown(void) {
    delete(pMeanValueFilter);
}

static void test_mean_value_is_zero_at_start() {
    TEST_ASSERT_EQUAL_FLOAT(0.0F, pMeanValueFilter->getFilteredValue());
}

static void test_mean_value_one_value() {
    pMeanValueFilter->addValue(42.0);
    float mean = pMeanValueFilter->getFilteredValue();
    TEST_ASSERT_EQUAL_FLOAT(42.0F, mean);
}

static void test_mean_value_multi_value() {
    pMeanValueFilter->addValue(42.0);
    pMeanValueFilter->addValue(43.0);
    pMeanValueFilter->addValue(44.0);
    float mean = pMeanValueFilter->getFilteredValue();
    TEST_ASSERT_EQUAL_FLOAT(43.0F, mean);
}

static void test_mean_value_after_reset_is_zero() {
    pMeanValueFilter->addValue(42.0);
    pMeanValueFilter->addValue(43.0);
    pMeanValueFilter->addValue(44.0);
    pMeanValueFilter->reset();
    TEST_ASSERT_EQUAL_FLOAT(0.0F, pMeanValueFilter->getFilteredValue());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_mean_value_is_zero_at_start);
    RUN_TEST(test_mean_value_one_value);
    RUN_TEST(test_mean_value_multi_value);
    RUN_TEST(test_mean_value_after_reset_is_zero);
    UNITY_END();

    return 0;
}
