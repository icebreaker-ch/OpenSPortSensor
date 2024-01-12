#include <unity.h>
#include "LinkedList.h"

struct S {
    int i;
};

static LinkedList<int> *pList;

void setUp(void) {
    pList = new LinkedList<int>();
}

void tearDown(void) {
    delete(pList);
}

void test_linked_list_is_empty() {
    TEST_ASSERT_NULL(pList->getHead());
}

void test_list_contains_all_added_elements() {
    pList->add(42);
    pList->add(17);
    pList->add(666);
    LinkedListElement<int> *p = pList->getHead();
    TEST_ASSERT_EQUAL_INT(666, p->element);
    p = p->pNext;
    TEST_ASSERT_EQUAL_INT(17, p->element);
    p = p->pNext;
    TEST_ASSERT_EQUAL_INT(42, p->element);
}

void test_next_for_last_element_is_null() {
    pList->add(42);
    LinkedListElement<int> *p = pList->getHead();
    TEST_ASSERT_NULL(p->pNext);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_linked_list_is_empty);
    RUN_TEST(test_list_contains_all_added_elements);
    RUN_TEST(test_next_for_last_element_is_null);
    UNITY_END();

    return 0;
}
