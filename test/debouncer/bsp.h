#ifndef BSP_H
#define BSP_H
#include <stdint.h>

void bsp_pin_mode(uint8_t pin, uint8_t mode);
uint8_t bsp_digitalRead(uint8_t pin); // No digital Read is used,so faking technique is used.
void bsp_set_fake_val(uint8_t val);   // for testing
#endif