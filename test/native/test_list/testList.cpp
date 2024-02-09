#include <unity.h>
#include <List.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_create_list_is_empty() {
    List<int> *pList = new List<int>();
    TEST_ASSERT_TRUE(pList->begin() == pList->end());
}

void test_insert_first_element_not_empty() {
    List<int> *pList = new List<int>();
    pList->add(42);
    TEST_ASSERT_FALSE(pList->begin() == pList->end());
}

void test_iterator_reference_element() {
    List<int> *pList = new List<int>();
    pList->add(42);
    List<int>::Iterator it = pList->begin();
    TEST_ASSERT_EQUAL(42, *it);
}

void test_iterator_next_element() {
    List<int> *pList = new List<int>();
    pList->add(42);
    pList->add(43);
    List<int>::Iterator it = pList->begin();
    ++it;
    TEST_ASSERT_EQUAL(42, *it);
}

void test_iterator_iterate() {
    int ref[3] = {11, 22, 33};

    List<int> *pList = new List<int>();
    pList->add(ref[2]);
    pList->add(ref[1]);
    pList->add(ref[0]);

    int arr[3];
    int index = 0;
    for (List<int>::Iterator it = pList->begin(); it != pList->end(); ++it) {
        arr[index++] = *it;
    }
    TEST_ASSERT_EQUAL_INT16_ARRAY(ref, arr, 3);
}

void test_iterator_iterate_postfix() {
    int ref[3] = {11, 22, 33};

    List<int> *pList = new List<int>();
    pList->add(ref[2]);
    pList->add(ref[1]);
    pList->add(ref[0]);

    int arr[3];
    int index = 0;
    List<int>::Iterator it = pList->begin();
    while (it != pList->end()) {
        arr[index++] = *it++;
    }
    TEST_ASSERT_EQUAL_INT16_ARRAY(ref, arr, 3);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_create_list_is_empty);
    RUN_TEST(test_insert_first_element_not_empty);
    RUN_TEST(test_iterator_reference_element);
    RUN_TEST(test_iterator_next_element);
    RUN_TEST(test_iterator_iterate);
    RUN_TEST(test_iterator_iterate_postfix);
    UNITY_END();
    return 0;
}
