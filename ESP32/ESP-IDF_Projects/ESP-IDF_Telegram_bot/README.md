# 📲 ESP32 Telegram Bot using ESP-IDF

This project demonstrates how to use an **ESP32** microcontroller to interact with the **Telegram Bot API** using `esp_http_client` and JSON parsing with `cJSON`. The bot can receive messages from a user and reply back — enabling basic two-way messaging from your ESP32 board to your Telegram account over Wi-Fi.

---

## ✨ Features

- Send and receive messages via Telegram using HTTPS
- Secure communication using Telegram’s root certificate
- Parses incoming messages using `cJSON`
- Simple configuration with placeholders for secrets
- Easily extendable for automation, IoT, remote monitoring, or alert systems

---

## 🛠 Requirements

| Component       | Description                          |
|----------------|--------------------------------------|
| Board          | ESP32 (tested on DevKit v1)          |
| SDK            | ESP-IDF v5.1.4 or later              |
| Internet       | Wi-Fi access for the ESP32 board     |
| Telegram       | Installed on your phone/PC           |

---

## 🧪 How It Works

- The ESP32 connects to Wi-Fi and polls the Telegram API endpoint `getUpdates`.
- It fetches the latest message, checks if it's from a valid user (`chat_id`), and logs or replies.
- You can customize the message response logic as per your application.

---

## 🤖 Creating a Telegram Bot

1. **Install Telegram**  
   Download Telegram from [Google Play](https://play.google.com/store/apps/details?id=org.telegram.messenger) or [App Store](https://apps.apple.com/app/telegram-messenger/id686449807).

2. **Create Bot with BotFather**  
   - Open Telegram, search for `@BotFather` or go to [t.me/BotFather](https://t.me/botfather)  
   - Send `/newbot` and follow the steps  
   - Give it a name and unique username  
   - You’ll get a **Bot Token** like:
     ```
     1234567890:XXXXXX-qQkZL9jxYszDjor8Yr81YJ3XXXXX
     ```
   - Save this token — this is required for your ESP32 to talk to Telegram

3. **Get Your Telegram User ID**  
   - Search for `@myidbot` or open [t.me/myidbot](https://t.me/myidbot)  
   - Send `/getid`  
   - Save the numeric ID you receive — this is your **Chat ID**

---

## 🧾 Configuration

Update `main/telegram_bot.c` with your credentials:

```c
#define WIFI_SSID           "YOUR_SSID"
#define WIFI_PASSWORD       "YOUR_WIFI_PASSWORD"
#define TELEGRAM_BOT_TOKEN  "YOUR_BOT_TOKEN"
#define TELEGRAM_CHAT_ID    "YOUR_TELEGRAM_CHAT_ID"
