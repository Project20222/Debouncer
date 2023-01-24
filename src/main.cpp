#include <Arduino.h>
#include "debouncer.h"
#include <stdint.h>

#define BTN1 33
#define BTN2 34

static bool init_ok = false;

void setup()
{
  Serial.begin(9600);
  delay(2000);

  // digital I/O pin
  uint8_t btn_pin[] = {BTN1, BTN2};

  if (debouncer_btn_init(btn_pin, sizeof(btn_pin)) == DEBOUCER_ERROR_OK)
  {
    init_ok = true;
  }
}

void loop()
{
  if (init_ok)
  {
    static uint8_t prev_state = HIGH;
    uint8_t current_state;
    uint8_t current_state2;

    debouncer_update_all_pin();
    current_state = debouncer_get_state(BTN1);

    if (current_state != prev_state)
    {
      prev_state = current_state;
      Serial.printf("State Button 1: %d", current_state);
    }

    debouncer_update_all_pin();
    current_state2 = debouncer_get_state(BTN2);

    if (current_state2 != prev_state)
    {
      prev_state = current_state2;
      Serial.printf("State Button 2: %d", current_state2);
    }
  }
}