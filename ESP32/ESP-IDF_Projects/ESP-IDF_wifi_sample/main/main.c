/**
 * @file wifi_connectivity.c
 *
 * @brief WiFi connectivity example for ESP32 using ESP-IDF.
 *
 * This is a simple example demonstrating how to connect to a WiFi network
 * and check internet connectivity using the ESP-IDF framework.
 *
 * Written by: [Your Name]
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_http_client.h"

#define WIFI_SSID "SOLO"
#define WIFI_PASS "asdfghjkl"
#define WIFI_MAXIMUM_RETRY 10
#define INTERNET_CHECK_INTERVAL_MS 5000 // Check internet connectivity every 5 seconds

#define INTERNET CHECK
static EventGroupHandle_t wifi_event_group;
static const char *TAG = "wifi_station";

static int retry_count = 0;

/**
 * @brief WiFi event handler.
 *
 * Handles events related to WiFi connection.
 */
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data) {
    if (event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (retry_count < WIFI_MAXIMUM_RETRY) {
            esp_wifi_connect();
            retry_count++;
            ESP_LOGI(TAG, "retry to connect to the AP (retry left %d )",WIFI_MAXIMUM_RETRY - retry_count);
        } else {
            ESP_LOGE(TAG, "Failed to connect to the AP after maximum retries");
        }
    }
}

/**
 * @brief IP event handler.
 *
 * Handles events related to obtaining an IP address.
 */
static void ip_event_handler(void* arg, esp_event_base_t event_base,
                             int32_t event_id, void* event_data) {
    if (event_id == IP_EVENT_STA_GOT_IP) {
        xEventGroupSetBits(wifi_event_group, BIT0);
    }
}

/**
 * @brief Initialize WiFi station mode.
 */
void wifi_init_sta(void) 
{
    wifi_event_group = xEventGroupCreate();

    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL);
    esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL, NULL);

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
        },
    };

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);
    esp_wifi_start();

    EventBits_t bits = xEventGroupWaitBits(wifi_event_group, BIT0, pdFALSE, pdFALSE, portMAX_DELAY);

    if (bits & BIT0) {
        ESP_LOGI(TAG, "Connected to WiFi network");
    } else {
        ESP_LOGE(TAG, "Failed to connect to WiFi network");
    }
}

/**
 * @brief Task to check internet connectivity.
 *
 * Continuously checks internet connectivity by sending HTTP requests.
 */
void check_internet_connectivity(void *pvParameters) 
{
    while (1) {
        esp_http_client_config_t config = {
            .url = "http://www.google.com", // Change this URL to a reliable server
        };
        esp_http_client_handle_t client = esp_http_client_init(&config);
        esp_err_t err = esp_http_client_perform(client);

        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Internet connectivity: Connected");
        } else {
            ESP_LOGE(TAG, "Internet connectivity: Disconnected");
        }

        esp_http_client_cleanup(client);
        vTaskDelay(INTERNET_CHECK_INTERVAL_MS / portTICK_PERIOD_MS);
    }
}

void app_main(void) 
{
    nvs_flash_init();
    wifi_init_sta();

    // Start task to check internet connectivity
    xTaskCreate(&check_internet_connectivity, "check_internet_connectivity", 4096, NULL, 5, NULL);
}
