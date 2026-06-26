# 📦 MagiBox: Smart IoT Secure Parcel Drop System

## 📌 Project Overview
**MagiBox** is an IoT-based smart parcel drop box designed to securely receive and store packages even when the user is not at home. It automatically detects parcel deliveries, tracks the number of items received, and sends real-time notifications via a Telegram bot.

Built using **Arduino Uno and ESP8266 Wi-Fi module**, the system enhances delivery security by preventing theft, missed deliveries, and package damage.

---

## ⚙️ Features
- 📡 Automatic parcel detection using IR Break Beam Sensor  
- 🔔 Real-time Telegram notifications via Wi-Fi (ESP8266)  
- 🔐 PIN-based secure access using 4×4 keypad  
- 🔒 Solenoid lock controlled via relay module  
- 📊 Parcel count tracking system  
- 💡 16×2 LCD real-time status display  
- 🔊 Buzzer feedback for alerts and errors  
- 🚨 Lockout system after multiple wrong PIN attempts  
- 🧠 Fully automated detection → notification → access workflow  

---

## 🧰 Hardware Components
- Arduino Uno R3  
- ESP8266 Wi-Fi Module (ESP-12E)  
- IR Break Beam Sensor ×2  
- 16×2 LCD with I2C Module  
- 4×4 Matrix Keypad  
- 5V Active Buzzer  
- 12V Solenoid Lock  
- 5V Relay Module  
- Buck Converter (LM2596)  
- Flyback Diode (1N4007)  
- Resistors, Capacitors, Jumper Wires  
- 12V Power Supply  
- Plywood Enclosure (31×21 cm)

---

## 🏗️ System Architecture
The system is divided into four layers:

- **Input Layer:** IR sensor + keypad  
- **Processing Layer:** Arduino Uno microcontroller  
- **Communication Layer:** ESP8266 Wi-Fi (Telegram Bot API)  
- **Output Layer:** LCD display, buzzer, solenoid lock  

---

## 🔄 How It Works
1. Parcel enters the drop chute  
2. IR sensor detects delivery  
3. Arduino increments parcel count  
4. System sends:
   - LCD update  
   - Buzzer alert  
   - Telegram notification  
5. User enters PIN on keypad  
6. If PIN is correct:
   - Solenoid unlocks  
   - Access granted message shown  
7. If PIN is wrong:
   - Access denied  
   - Alarm triggers  
   - Lockout after multiple attempts  

---

## 💻 Software Used
- Arduino IDE  
- C/C++ (Embedded Programming)  
- Libraries:
  - SoftwareSerial.h  
  - Wire.h  
  - LiquidCrystal_I2C.h  
  - Keypad.h  
- Fritzing (Circuit Design)  
- Tinkercad (Simulation)

---

## 🚀 Innovations
- 🌐 Telegram IoT notifications (no SIM required)  
- 🔐 PIN-based digital security system  
- 📦 One-way anti-theft parcel chute design  
- ⚡ Low-cost Arduino-based automation  
- 📡 Real-time parcel tracking system  

---

## 🧪 Performance Summary
- Accurate parcel detection with IR sensor  
- Fast Telegram alerts (Wi-Fi dependent)  
- Reliable PIN authentication system  
- Stable lock mechanism  
- Clear LCD + buzzer feedback  

---

## 📈 Future Improvements
- Mobile app integration  
- Solar-powered system  
- Camera-based delivery verification  
- Fingerprint/RFID authentication  
- Cloud-based parcel history logs  
- Larger storage capacity  

---

## 🎯 Conclusion
MagiBox provides a low-cost, reliable, and secure IoT solution for unattended parcel delivery. It integrates automation, real-time communication, and physical security into a single embedded system suitable for modern smart homes.

---
