/**
 * @file telegram_bot.c
 * @brief ESP32 with Telegram Bot: Responds to "Hello ESP" with "Hello BOSS"
 *
 * This program connects an ESP32 to Wi-Fi, then polls Telegram updates,
 * and sends a reply when a specific message is received.
 */

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "cJSON.h"

//--------------------------------------------
// Configuration Macros
// --------------------------------------------
#define WIFI_SSID           "YOUR_WIFI_SSID"
#define WIFI_PASSWORD       "YOUR_WIFI_PASSWORD"
#define TELEGRAM_BOT_TOKEN  "YOUR_TELEGRAM_BOT_TOKEN"
#define TELEGRAM_CHAT_ID    "YOUR_CHAT_ID"
#define REPLY               "Hello BOSS"
#define KEYWORD             "Hello ESP"
#define MAX_HTTP_BUFFER     (32 * 1024)
#define POLL_INTERVAL_MS    100
#define MESSAGE_FETCH_LIMIT 2

//--------------------------------------------
// Globals
//--------------------------------------------
static const char *TAG = "T_BOT";
static EventGroupHandle_t wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0

static char response_buffer[MAX_HTTP_BUFFER];
static int response_len = 0;
static int last_update_id = 0;

//--------------------------------------------
// Telegram Root Certificate
//--------------------------------------------
const char *TELEGRAM_CERT = 
"-----BEGIN CERTIFICATE-----\n"
"MIIE0DCCA7igAwIBAgIBBzANBgkqhkiG9w0BAQsFADCBgzELMAkGA1UEBhMCVVMx\n"
"EDAOBgNVBAgTB0FyaXpvbmExEzARBgNVBAcTClNjb3R0c2RhbGUxGjAYBgNVBAoT\n"
"EUdvRGFkZHkuY29tLCBJbmMuMTEwLwYDVQQDEyhHbyBEYWRkeSBSb290IENlcnRp\n"
"ZmljYXRlIEF1dGhvcml0eSAtIEcyMB4XDTExMDUwMzA3MDAwMFoXDTMxMDUwMzA3\n"
"MDAwMFowgbQxCzAJBgNVBAYTAlVTMRAwDgYDVQQIEwdBcml6b25hMRMwEQYDVQQH\n"
"EwpTY290dHNkYWxlMRowGAYDVQQKExFHb0RhZGR5LmNvbSwgSW5jLjEtMCsGA1UE\n"
"CxMkaHR0cDovL2NlcnRzLmdvZGFkZHkuY29tL3JlcG9zaXRvcnkvMTMwMQYDVQQD\n"
"EypHbyBEYWRkeSBTZWN1cmUgQ2VydGlmaWNhdGUgQXV0aG9yaXR5IC0gRzIwggEi\n"
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC54MsQ1K92vdSTYuswZLiBCGzD\n"
"BNliF44v/z5lz4/OYuY8UhzaFkVLVat4a2ODYpDOD2lsmcgaFItMzEUz6ojcnqOv\n"
"K/6AYZ15V8TPLvQ/MDxdR/yaFrzDN5ZBUY4RS1T4KL7QjL7wMDge87Am+GZHY23e\n"
"cSZHjzhHU9FGHbTj3ADqRay9vHHZqm8A29vNMDp5T19MR/gd71vCxJ1gO7GyQ5HY\n"
"pDNO6rPWJ0+tJYqlxvTV0KaudAVkV4i1RFXULSo6Pvi4vekyCgKUZMQWOlDxSq7n\n"
"eTOvDCAHf+jfBDnCaQJsY1L6d8EbyHSHyLmTGFBUNUtpTrw700kuH9zB0lL7AgMB\n"
"AAGjggEaMIIBFjAPBgNVHRMBAf8EBTADAQH/MA4GA1UdDwEB/wQEAwIBBjAdBgNV\n"
"HQ4EFgQUQMK9J47MNIMwojPX+2yz8LQsgM4wHwYDVR0jBBgwFoAUOpqFBxBnKLbv\n"
"9r0FQW4gwZTaD94wNAYIKwYBBQUHAQEEKDAmMCQGCCsGAQUFBzABhhhodHRwOi8v\n"
"b2NzcC5nb2RhZGR5LmNvbS8wNQYDVR0fBC4wLDAqoCigJoYkaHR0cDovL2NybC5n\n"
"b2RhZGR5LmNvbS9nZHJvb3QtZzIuY3JsMEYGA1UdIAQ/MD0wOwYEVR0gADAzMDEG\n"
"CCsGAQUFBwIBFiVodHRwczovL2NlcnRzLmdvZGFkZHkuY29tL3JlcG9zaXRvcnkv\n"
"MA0GCSqGSIb3DQEBCwUAA4IBAQAIfmyTEMg4uJapkEv/oV9PBO9sPpyIBslQj6Zz\n"
"91cxG7685C/b+LrTW+C05+Z5Yg4MotdqY3MxtfWoSKQ7CC2iXZDXtHwlTxFWMMS2\n"
"RJ17LJ3lXubvDGGqv+QqG+6EnriDfcFDzkSnE3ANkR/0yBOtg2DZ2HKocyQetawi\n"
"DsoXiWJYRBuriSUBAA/NxBti21G00w9RKpv0vHP8ds42pM3Z2Czqrpv1KrKQ0U11\n"
"GIo/ikGQI31bS/6kA1ibRrLDYGCD+H1QQc7CoZDDu+8CL9IVVO5EFdkKrqeKM+2x\n"
"LXY2JtwE65/3YR8V3Idv7kaWKK2hJn0KCacuBKONvPi8BDAB\n"
"-----END CERTIFICATE-----\n";

//--------------------------------------------
// Wi-Fi Event Handler
//--------------------------------------------
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data) 
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        esp_wifi_connect();
        ESP_LOGW(TAG, "Wi-Fi connection lost. Retrying...");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "Got IP: " IPSTR, IP2STR(&event->ip_info.ip));
        xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

//--------------------------------------------
// Initialize Wi-Fi
//--------------------------------------------
static void wifi_init(void) 
{
    wifi_event_group = xEventGroupCreate();
    esp_netif_create_default_wifi_sta();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL, NULL));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASSWORD,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "Wi-Fi initialized...");
}

//--------------------------------------------
// URL Encoding
//--------------------------------------------
static char *url_encode(const char *src, char *dst, size_t dst_len) 
{
    const char *hex = "0123456789ABCDEF";
    char *p = dst;

    while (*src && (p - dst < dst_len - 4)) {
        if (isalnum((unsigned char)*src) || *src == '-' || *src == '_' || *src == '.' || *src == '~') {
            *p++ = *src;
        } else {
            *p++ = '%';
            *p++ = hex[(*src >> 4) & 0xF];
            *p++ = hex[*src & 0xF];
        }
        src++;
    }
    *p = '\0';
    return dst;
}

//--------------------------------------------
// Send Telegram Message
//--------------------------------------------
static void telegram_send_message(const char *msg) 
{
    char encoded_msg[256];
    url_encode(msg, encoded_msg, sizeof(encoded_msg));

    char url[512];
    snprintf(url, sizeof(url),
             "https://api.telegram.org/bot%s/sendMessage?chat_id=%s&text=%s",
             TELEGRAM_BOT_TOKEN, TELEGRAM_CHAT_ID, encoded_msg);

    esp_http_client_config_t config = {
        .url = url,
        .method = HTTP_METHOD_GET,
        .cert_pem = TELEGRAM_CERT,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "Message sent: %s", msg);
    } else {
        ESP_LOGE(TAG, "Failed to send message: %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
}

//--------------------------------------------
// HTTP Response Event Handler
//--------------------------------------------
static esp_err_t http_event_handler(esp_http_client_event_t *evt) 
{
    if (evt->event_id == HTTP_EVENT_ON_DATA && !esp_http_client_is_chunked_response(evt->client)) {
        int copy_len = evt->data_len;
        if ((response_len + copy_len) < MAX_HTTP_BUFFER) {
            memcpy(response_buffer + response_len, evt->data, copy_len);
            response_len += copy_len;
            response_buffer[response_len] = '\0';
        }
    }
    return ESP_OK;
}

//--------------------------------------------
// Fetch Telegram Messages
//--------------------------------------------
static void telegram_fetch_updates(void) 
{
    response_len = 0;

    char url[256];
    snprintf(url, sizeof(url),
             "https://api.telegram.org/bot%s/getUpdates?offset=%d&limit=%d",
             TELEGRAM_BOT_TOKEN, last_update_id + 1, MESSAGE_FETCH_LIMIT);

    esp_http_client_config_t config = {
        .url = url,
        .cert_pem = TELEGRAM_CERT,
        .event_handler = http_event_handler,
        .buffer_size = 4096,
        .timeout_ms = 10000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        cJSON *root = cJSON_Parse(response_buffer);
        if (root) {
            cJSON *result = cJSON_GetObjectItem(root, "result");
            int count = cJSON_GetArraySize(result);
            for (int i = 0; i < count; i++) {
                cJSON *item = cJSON_GetArrayItem(result, i);
                cJSON *message = cJSON_GetObjectItem(item, "message");
                cJSON *text = cJSON_GetObjectItem(message, "text");
                ESP_LOGI(TAG, "Message received: %s",text->valuestring);
                if (cJSON_IsString(text) && strcmp(text->valuestring, KEYWORD) == 0) {
                    telegram_send_message(REPLY);
                }
                cJSON *update_id = cJSON_GetObjectItem(item, "update_id");
                if (cJSON_IsNumber(update_id)) {
                    last_update_id = update_id->valueint;
                }
            }
            cJSON_Delete(root);
        } else {
            ESP_LOGW(TAG, "Failed to parse JSON. Maybe empty?");
        }
    } else {
        ESP_LOGE(TAG, "Update fetch failed::: %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
}

//--------------------------------------------
// Telegram Polling Task
//--------------------------------------------
static void telegram_task(void *pvParameters) 
{
    while (true) {
        telegram_fetch_updates();
        vTaskDelay(pdMS_TO_TICKS(POLL_INTERVAL_MS));
    }
}

//--------------------------------------------
// Main Function
//--------------------------------------------
void app_main(void) 
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init();
    xEventGroupWaitBits(wifi_event_group, WIFI_CONNECTED_BIT, pdFALSE, pdFALSE, portMAX_DELAY);

    ESP_LOGI(TAG, "Wi-Fi connected to: %s", WIFI_SSID);
    xTaskCreate(&telegram_task, "telegram_task", 8192, NULL, 5, NULL);
}
