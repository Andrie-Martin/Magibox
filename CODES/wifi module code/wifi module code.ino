#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <SoftwareSerial.h>

// ─── WiFi ───
const char* ssid = "ssid of wifi";
const char* password = "pass of wifi";

// ─── Telegram ───
#define BOTtoken "token"
#define CHAT_ID "chat id"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// ─── Software Serial mula Arduino ───
SoftwareSerial arduinoSerial(D2, D3); // RX, TX

void setup() {
  Serial.begin(115200);
  arduinoSerial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);

  Serial.println("ESP8266 Ready!");
}

void loop() {
  if (arduinoSerial.available()) {
    String msg = arduinoSerial.readStringUntil('\n');
    msg.trim();

    if (msg.startsWith("PARCEL:")) {
      int count = msg.substring(7).toInt();

      // Message 1: Parcel received alert
      bot.sendMessage(CHAT_ID, "📦 Parcel Received!", "");

      // Message 2: Total count
      bot.sendMessage(CHAT_ID, "📊 Total parcels inside the box: " + String(count), "");

      Serial.println("Telegram messages sent! Count: " + String(count));
    }
  }
}