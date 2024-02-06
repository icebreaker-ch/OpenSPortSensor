#include <unity.h>
#include <List.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_create_list_is_empty() {
    List<int> *pList = new List<int>();
    TEST_ASSERT_NULL(pList->getHead());
}

void test_insert_element_non_empty() {
    List<int> *pList = new List<int>();
    pList->add(42);
    TEST_ASSERT_NOT_NULL(pList->getHead());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_create_list_is_empty);
    RUN_TEST(test_insert_element_non_empty);
    UNITY_END();
    return 0;
}
