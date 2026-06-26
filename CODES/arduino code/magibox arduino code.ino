#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "ADD WIFI NAME HERE";
const char* password = "ADD WIFI PASSWORD HERE";
#define BOTtoken "ADD TELEGRAM BIT TOKEN OF THE BOT HERE"
#define CHAT_ID "ADD CHAT ID HERE"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Timer variables
unsigned long previousMillis = 0;
const long interval = 5000; // 5 seconds (5000 milliseconds)

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);
  
  Serial.println("\nHanda na! Magse-send ng message kada 5 segundo.");
}

void loop() {
  unsigned long currentMillis = millis();

  // Check kung lumipas na ang 5 seconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // I-reset ang timer
    
    Serial.println("Nagse-send ng automatic message...");
    
    // I-send ang message
    if (bot.sendMessage(CHAT_ID, "Parcel Received", "")) {
      Serial.println("Tagumpay ang pag-send!");
    } else {
      Serial.println("May error sa pag-send.");
    }
  }
}