#include "I2C_Driver.h"
#include "PWR_Key.h"
#include "ST7789.h"
#include <Arduino.h>

#define LED_PIN 33

static lv_obj_t *splash_label = NULL;

static void show_splash() {
  /* Create a simple centered label on the active screen */
  lv_obj_t *scr = lv_scr_act();
  splash_label = lv_label_create(scr);
  lv_label_set_text(splash_label, "Hospital BLE\nStarting...");
  lv_obj_center(splash_label);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // Initialize hardware and LVGL
  LCD_Init();  // initializes SPI, panel and touch
  LVGL_Init(); // initializes lvgl, display driver and tick timer

  // Show a simple splash while setup continues
  show_splash();

  Serial.println("Setup complete");
}

void loop() {
  // Let LVGL handle tasks (timers, animations, redraws)
  lv_timer_handler();

  // Simple LED blink to show the MCU is alive
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}