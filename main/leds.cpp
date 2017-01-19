#include "leds.h"
#include "esp_log.h"

static const char *TAG = "leds";

static struct led_color_t led_strip_buf_1[LED_STRIP_LENGTH];
static struct led_color_t led_strip_buf_2[LED_STRIP_LENGTH];

void leds_initialize()
{
  struct led_strip_t led_strip = {
    .rgb_led_type = RGB_LED_TYPE_APA106,
    .led_strip_length = LED_STRIP_LENGTH,
    .rmt_channel = LED_STRIP_RMT_CHANNEL_NUM,
    .rmt_interrupt_num = LED_STRIP_RMT_INTR_NUM,
    .gpio = GPIO_NUM_23,
    .showing_buf_1 = true, // C++ requires all of the elements in the constructor
    .led_strip_buf_1 = led_strip_buf_1,
    .led_strip_buf_2 = led_strip_buf_2,
    .access_semaphore = NULL
  };
  led_strip.access_semaphore = xSemaphoreCreateBinary();

  bool led_init_ok = led_strip_init(&led_strip);
  if (led_init_ok) {
    ESP_LOGI(TAG, "Initialised.");
  } else {
    ESP_LOGE(TAG, "Failed to initialise.");
  }
}
