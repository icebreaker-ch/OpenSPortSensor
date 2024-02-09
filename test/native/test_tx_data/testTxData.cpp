#include <unity.h>
#include <TxData.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_create_tx_data() {
    unsigned char buffer[TxData::LEN];
    TxData txData = TxData(0x110, 12345L);
    txData.getData(buffer);
    unsigned char expected[] = {16, 16, 1, 57, 48, 0, 0, 117};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, buffer, TxData::LEN);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_create_tx_data);
    UNITY_END();
    return 0;
}
