#include <unity.h>
#include <RingBuffer.h>

static RingBuffer<int> *pRingBuffer;

void setUp(void) {
    pRingBuffer = new RingBuffer<int>(5);
}

void tearDown(void) {
    delete pRingBuffer;
}

void test_empty_buffer_returns_size_0() {
    TEST_ASSERT_EQUAL_UINT16(0, pRingBuffer->getCurrentSize());
}

void test_current_size() {
    pRingBuffer->add(1);
    TEST_ASSERT_EQUAL_UINT16(1, pRingBuffer->getCurrentSize());
    pRingBuffer->add(2);
    TEST_ASSERT_EQUAL_UINT16(2, pRingBuffer->getCurrentSize());
    pRingBuffer->add(7);
    TEST_ASSERT_EQUAL_UINT16(3, pRingBuffer->getCurrentSize());
}

void test_max_size() {
    for (int i = 0; i < 10; ++i)
        pRingBuffer->add(i);
    TEST_ASSERT_EQUAL_INT16(5, pRingBuffer->getCurrentSize());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_empty_buffer_returns_size_0);
    RUN_TEST(test_current_size);
    RUN_TEST(test_max_size);
    UNITY_END();
    return 0;
}
