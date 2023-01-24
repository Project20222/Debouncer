#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <stdint.h>

// Error Codes
#define DEBOUCER_ERROR_OK 100
#define DEBOUNCER_UNINITIAL 101
#define DEBOUNCER_ERROR_INVALID_PIN 102
#define DEBOUNCER_TOO_MANY_BUTTONS 103
#define DEBOUNCER_ERROR_SAME_PIN 104
#define DEBOUNCER_ERROR_OUT_OF_RANGE 105
#define DEBOUNCER_ERROR_PIN_NOT_FOUND 106

// Debouncer States
#define DEBOUNCER_LOW 0
#define DEBOUNCER_HIGH 1
#define DEBOUNCER_RISING_EDGE 2
#define DEBOUNCER_FALLING_EDGE 3

// Constants
#define MAX_DEBOUNCER_PIN 57
#define MAX_BTN 8
#define NO_OF_REPETITION 5

/**
 * @brief To initialze the init function
 * @param pins Array of pins
 * @param pin_count No.of pins used by the buttons
 * @return Error codes
 */
uint8_t
debouncer_btn_init(uint8_t *pins, uint8_t pin_count);

/**
 * @brief To update the Pin state
 */
void debouncer_update_all_pin();

/**
 * @brief To get the debounced state
 * @param pin Pin used by the debouncer
 * @return Debounced State or error codes
 */
uint8_t debouncer_get_state(uint8_t pin);

#endif