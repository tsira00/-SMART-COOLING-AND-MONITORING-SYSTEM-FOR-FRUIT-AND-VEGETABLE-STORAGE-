# Smart Fruit and Vegetable Storage System

## Overview
This project presents an intelligent system for monitoring and maintaining optimal conditions for fruit and vegetable storage. The system is built on an **Arduino Uno** and integrates multiple sensors to monitor environmental conditions, including humidity, light, water level, and gas. Sensor data is displayed on an **LCD screen**, and critical conditions trigger visual and auditory alerts via **LED lights** and a **buzzer**.  

The main goal of this project is to **prevent food spoilage** by providing real-time monitoring and alerts.

---

## Components
The following hardware components are used in this project:

1. **Humidity Sensor (DHT11/DHT22)** – monitors temperature and humidity  
2. **Water Level Sensor** – measures water levels, triggers LEDs and a servo motor  
3. **Light Sensor (LDR)** – measures ambient light, controls LED and buzzer  
4. **Gas Sensor (MQ)** – detects harmful gases, triggers LED and buzzer  
5. **Servo Motor** – used for actuating mechanisms based on sensor readings  
6. **LCD Screen (I2C 16x2)** – displays sensor data  
7. **LED Lights** – visual alert indicators  
8. **Buzzer** – audible alert for critical conditions  

---

## Relevance
Efficient food storage is a crucial issue in modern agriculture and retail. Improper storage leads to significant annual losses due to spoilage caused by incorrect **temperature, humidity, and light control**.  

This system is particularly beneficial for:  
- Farmers  
- Retail food sellers  

By monitoring all key environmental parameters, the system helps maintain optimal storage conditions and reduces food waste.

---

## Circuit Description
The sensors and components are connected to the Arduino pins as follows:

| Component           | Arduino Pin |
|--------------------|------------|
| Light Sensor (LDR)  | A1         |
| Light LED           | 10         |
| Water Sensor        | A0         |
| Red LED             | 8          |
| Yellow LED          | 7          |
| Blue LED            | 6          |
| Servo Motor         | 9          |
| Gas Sensor (Digital)| 5          |
| Gas Alert LED       | 4          |
| Buzzer              | 3          |
| DHT Sensor (Temp/Humidity) | 2  |

---

## Results
- Successfully monitored **humidity, light, gas, and water level**  
- LCD display provided **visual feedback** in real-time  
- LED lights and buzzer allowed **instant alerts**  
- System logic ensures **timely intervention to prevent food spoilage**

---

## Advantages Over Existing Systems
- Provides **real-time alerts** for multiple environmental factors simultaneously  
- Alerts remain active until the issue is resolved  
- Customizable parameters for **temperature, humidity, and water level thresholds**  
- Allows continuous **environment monitoring and management**  
- Helps users **store food safely for longer periods**

---

## Conclusion
This project demonstrates how **simple technology** can be integrated to create a smart storage system for agricultural or retail use. By combining multiple sensors with Arduino Uno, the system provides continuous monitoring and practical alerts, improving food storage efficiency and reducing waste.
