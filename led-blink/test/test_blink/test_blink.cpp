#include <unity.h>
#include "Blink.h"
#include <stdint.h>

static bool mockPin = false;

void test_blink_toggles_based_on_time(void) {
    mockPin = false;
    Blink b([](bool s){ mockPin = s; }, 100, 150);

    // start at time 0
    b.update(0);
    TEST_ASSERT_FALSE(b.state());
    TEST_ASSERT_FALSE(mockPin);

    // after 100ms -> should turn ON
    b.update(100);
    TEST_ASSERT_TRUE(b.state());
    TEST_ASSERT_TRUE(mockPin);

    // before 250ms (100 + 150) still ON
    b.update(249);
    TEST_ASSERT_TRUE(b.state());
    TEST_ASSERT_TRUE(mockPin);

    // at 250ms -> should turn OFF
    b.update(250);
    TEST_ASSERT_FALSE(b.state());
    TEST_ASSERT_FALSE(mockPin);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_blink_toggles_based_on_time);
    return UNITY_END();
}
