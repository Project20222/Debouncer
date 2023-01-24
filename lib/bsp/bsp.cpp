#include "bsp.h"

#include <Arduino.h>

uint8_t bsp_digitalRead(uint8_t pin)
{
    return digitalRead(pin);
}
void bsp_pin_mode(uint8_t pin, uint8_t mode)
{
    pinMode(pin, mode);
}