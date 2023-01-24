#include <unity.h>
#include <stdint.h>
#include "bsp.h"
void test_debouncer_btn_init()

{

    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_UNINITIAL, debouncer_get_state(0));

    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_ERROR_INVALID_PIN, (debouncer_btn_init(NULL, 1)));

    uint8_t too_many_button[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_TOO_MANY_BUTTONS, (debouncer_btn_init(button_size, sizeof(too_many_button))));

    uint8_t same_pin_no[] = {33, 34, 40, 34, 36, 56};
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_TOO_MANY_BUTTONS, (debouncer_btn_init(same_pin_no, sizeof(same_pin_no))));

    uint8_t pin_out_of_range[] = {33, 34, 40, 34, 36, 60};
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_TOO_MANY_BUTTONS, (debouncer_btn_init(pin_out_of_range, sizeof(pin_out_of_range))));

    uint8_t pin_ok[] = {33, 34, 40, 35, 36, 54};
    TEST_ASSERT_EQUAL_UINT8(DEBOUCER_ERROR_OK, (debouncer_btn_init(pin_ok, sizeof(pin_ok))));

    for (int i = 0; i < sizeof(pin_ok); i++)
    {
        TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(i));
    }
}
void test_debouncer_get_state()
{
    uint8_t pin_ok[] = {33, 34};

    // TESTING PIN33
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_TOO_MANY_BUTTONS, (debouncer_btn_init(button_size, sizeof(too_many_button))));
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_ERROR_PIN_NOT_FOUND, debouncer_get_state(37));
    // Initally the state will be high because of Pullup Resistor
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));

    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    bsp_set_fake_val(0);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    // 1
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    // 2
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    // 3
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    // 4
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));
    // when counter is 5 edge will be found
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_FALLING_EDGE, debouncer_get_state(33));
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    bsp_set_fake_val(0);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    // 1 time
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    // 2 time
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    // 3 time
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    // 4 time
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_LOW, debouncer_get_state(33));
    // when counter=5 edge will be found
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_RISING_EDGE, debouncer_get_state(33));
    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(33));

    // TESTING SECOND PIN 34

    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_TOO_MANY_BUTTONS, (debouncer_btn_init(button_size, sizeof(too_many_button))));
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_ERROR_PIN_NOT_FOUND, debouncer_get_state(37));
    // Initally the state will be high because of Pullup Resistor
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    bsp_set_fake_val(0);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    bsp_set_fake_val(0);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 1
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 2
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 3
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    bsp_set_fake_val(0);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    bsp_set_fake_val(1);
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 1
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 2
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 3
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // 4
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debouncer_get_state(34));
    // when counter becomes 5 edge will be found
    debouncer_update_all_pin();
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_FALLING_EDGE, debouncer_get_state(34));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_debouncer_btn_init);
    RUN_TEST(test_debouncer_get_state);
    return 0;
}