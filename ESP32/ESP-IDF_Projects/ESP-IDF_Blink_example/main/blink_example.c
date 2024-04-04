/**
 * @file blink_example.c
 *
 * @brief Blink example for ESP32 using ESP-IDF.
 *
 * This is a simple example demonstrating how to blink an LED connected to a GPIO pin
 * using the ESP-IDF framework. The LED blinks with a 2-second interval.
 *
 * Written by: ABHITHLAL C
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN 2

void app_main() 
{
    // Set GPIO pin direction to OUTPUT
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Infinite loop to toggle the LED
    while (1) 
    {
        // Log message indicating LED is turning ON
        ESP_LOGI("LED","LED ON!!!");
        
        // Turn ON the LED by setting GPIO pin level to HIGH
        gpio_set_level(LED_PIN, 1);
        
        // Delay for 2 seconds
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        
        // Log message indicating LED is turning OFF
        ESP_LOGI("LED","LED OFF!!!");
        
        // Turn OFF the LED by setting GPIO pin level to LOW
        gpio_set_level(LED_PIN, 0);
        
        // Delay for 2 seconds
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
