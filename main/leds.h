#pragma once

#include "led_strip/led_strip.h"

#define LED_STRIP_LENGTH 2
#define LED_STRIP_RMT_CHANNEL_NUM RMT_CHANNEL_5
#define LED_STRIP_RMT_INTR_NUM 19U

void leds_initialize();
