/**
 * @TODO
 */
#include "unity.h"
#include "list.h"

#include <stdio.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_add(void) {
    //test stuff
    TEST_ASSERT_TRUE(1);
}

void test_delete(void) {
    //more test stuff
    TEST_ASSERT_TRUE(1);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_delete);
    return UNITY_END();
}

