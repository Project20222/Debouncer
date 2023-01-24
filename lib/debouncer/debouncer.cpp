
#include "debouncer.h"
#include "bsp.h"
#include <stdint.h>

#define PULLUP 2
// initialization
static bool initi = false;
uint8_t btn_pins[MAX_BTN] = {0};
uint8_t pin_no[MAX_BTN] = {0};
uint8_t btn_state[MAX_BTN] = {0};
uint8_t btn_counter[MAX_BTN] = {0};
uint8_t btn_count = 0, i;
uint8_t pin;
uint8_t current_state;
uint8_t result;

static bool same_pin_num(uint8_t *pins, uint8_t pin_count)
{
    bool same_num = false;
    for (i = 0; i < pin_count; i++)
    {
        if (pins[i] == pins[i + 1])
        {
            same_num = true;
        }
    }
    return same_num;
}

static bool pin_out_of_range(uint8_t *pins, uint8_t pin_count)
{
    bool out_of_range = false;
    for (i = 0; i < pin_count; i++)
    {
        if (pins[i] > MAX_DEBOUNCER_PIN)
        {
            out_of_range = true;
        }
    }
    return out_of_range;
}

uint8_t debouncer_btn_init(uint8_t *pins, uint8_t pin_count)
{
    // Error checking related to test cases
    if (pins == 0)
    {
        result = DEBOUNCER_ERROR_INVALID_PIN;
    }
    else if (pin_count > MAX_BTN)
    {
        result = DEBOUNCER_TOO_MANY_BUTTONS;
    }
    else if (same_pin_num(pins, pin_count))
    {
        result = DEBOUNCER_ERROR_SAME_PIN;
    }
    else if (pin_out_of_range(pins, pin_count))
    {
        result = DEBOUNCER_ERROR_OUT_OF_RANGE;
    }

    else if (pin_count < MAX_BTN)
    {
        for (uint8_t i = 0; i < pin_count; i++)
        {
            btn_pins[i] = pins[i];
            btn_state[i] = DEBOUNCER_HIGH;
            btn_counter[i] = 0;
            bsp_pin_mode(btn_pins[i], 2);
        }
        initi = true;
    }
    btn_count = pin_count;

    return DEBOUCER_ERROR_OK;
}

void debouner_get_index(uint8_t index)
{

    if (btn_state[index] == DEBOUNCER_FALLING_EDGE)
    {
        btn_state[index] = DEBOUNCER_LOW;
    }
    else if (btn_state[index] == DEBOUNCER_RISING_EDGE)
    {
        btn_state[index] = DEBOUNCER_HIGH;
    }

    pin = btn_pins[index];

    current_state = bsp_digitalRead(pin);

    if (current_state == btn_state[index])
    {
        btn_counter[index] = 0;
    }
    else
    {
        btn_counter[index]++;
        if (btn_counter[index] == NO_OF_REPETITION)
        {

            if (btn_state[index] == DEBOUNCER_HIGH)
            {
                btn_state[index] = DEBOUNCER_FALLING_EDGE;
            }
            else
            {
                btn_state[index] = DEBOUNCER_RISING_EDGE;
            }
            btn_counter[index] = 0;
        }
    }
}
void debouncer_update_all_pin()
{
    if (initi)
    {
        for (i = 0; i < btn_count; i++)
        {
            debouner_get_index(i);
        }
    }
}
uint8_t debouncer_get_state(uint8_t pin)
{
    uint8_t state_value = 0;
    bool found = false;
    if (!initi)
    {
        state_value = DEBOUNCER_UNINITIAL;
    }

    else
    {

        for (i = 0; i < MAX_BTN; i++)
        {
            if (pin == btn_pins[i])
            {
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        state_value = DEBOUNCER_ERROR_PIN_NOT_FOUND;
    }
    // function for finding the pin

    return state_value;
}
