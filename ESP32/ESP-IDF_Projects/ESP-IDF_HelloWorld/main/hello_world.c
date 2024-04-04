/**
 * @file hello_world.c
 *
 * @brief Simple "Hello World" example for ESP32 using ESP-IDF.
 *
 * This is a simple example demonstrating how to print messages to the console using printf
 * and the ESP-IDF logging library. It also demonstrates how to delay execution using FreeRTOS
 * tasks and restart the ESP32 after a certain period of time.
 *
 * Written by: ABHITHLAL C
 */

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief Entry point of the application.
 */
void app_main(void)
{
    // Print "Hello World!" to the console using printf
    printf("Hello World!\n");

    // Log "Hello World!" with INFO level using ESP-IDF logging
    ESP_LOGI("INFO","Demonstrating  Info : Hello World!");

    // Log "Hello World!" with WARNING level using ESP-IDF logging
    ESP_LOGW("WARNING","Demonstrating Warning: Hello World!");

    // Log "Hello World!" with ERROR level using ESP-IDF logging
    ESP_LOGE("ERROR","Demonstrating Error: Hello World!");

    // Count down and restart the ESP32
    for(int i = 10; i >= 0; i--)
    {
        // Print the countdown message to the console
        printf("Restarting in %d sec \n", i);

        // Delay execution for 1 second using FreeRTOS vTaskDelay
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    // Restart the ESP32
    esp_restart();
}
