#include <unity.h>
#include <MeanValueFilter.h>

static MeanValueFilter *pMeanValueFilter;

void setUp(void) {
    pMeanValueFilter = new MeanValueFilter(5);
}

void tearDown(void) {
    delete(pMeanValueFilter);
}

void test_mean_value_count_is_zero_at_start() {
    TEST_ASSERT_EQUAL_UINT16(0, pMeanValueFilter->getNumValues());
}

void test_mean_value_count() {
    pMeanValueFilter->addValue(1.0);
    unsigned int count = pMeanValueFilter->getNumValues();
    TEST_ASSERT_EQUAL_UINT16(1, pMeanValueFilter->getNumValues());
    pMeanValueFilter->addValue(2.0);
    pMeanValueFilter->addValue(3.0);
    pMeanValueFilter->addValue(4.0);
    TEST_ASSERT_EQUAL_UINT16(4, pMeanValueFilter->getNumValues());
}

void test_mean_value_one_value() {
    pMeanValueFilter->addValue(42.0);
    float mean = pMeanValueFilter->getFilteredValue();
    TEST_ASSERT_EQUAL_FLOAT(42.0F, mean);
}

void test_mean_value_multi_value() {
    pMeanValueFilter->addValue(42.0);
    pMeanValueFilter->addValue(43.0);
    pMeanValueFilter->addValue(44.0);
    float mean = pMeanValueFilter->getFilteredValue();
    TEST_ASSERT_EQUAL_FLOAT(43.0F, mean);
}

void test_mean_value_count_after_reset_is_zero() {
    pMeanValueFilter->addValue(42.0);
    pMeanValueFilter->addValue(43.0);
    pMeanValueFilter->addValue(44.0);
    pMeanValueFilter->reset();
    TEST_ASSERT_EQUAL_UINT16(0, pMeanValueFilter->getNumValues());    
}

void test_mean_value_after_reset_is_zero() {
    pMeanValueFilter->addValue(42.0);
    pMeanValueFilter->addValue(43.0);
    pMeanValueFilter->addValue(44.0);
    pMeanValueFilter->reset();
    TEST_ASSERT_EQUAL_FLOAT(0.0F, pMeanValueFilter->getFilteredValue());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_mean_value_count_is_zero_at_start);
    RUN_TEST(test_mean_value_count);
    RUN_TEST(test_mean_value_one_value);
    RUN_TEST(test_mean_value_multi_value);
    RUN_TEST(test_mean_value_count_after_reset_is_zero);
    RUN_TEST(test_mean_value_after_reset_is_zero);
    UNITY_END();

    return 0;
}
