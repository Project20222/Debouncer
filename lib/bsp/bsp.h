#ifndef BSP_H
#define BSP_H

#include <Arduino.h>
#include <stdint.h>

/**
 * @brief Same function of DigitalRead in Arduino
 * @param pin
 * @return uint8_t Pin of teensy3.5
 */

uint8_t bsp_digitalRead(uint8_t pin);

void bsp_pin_mode(uint8_t pin, uint8_t mode);

#endif