#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#include <Servo.h>  // სერვოს ბიბლიოთეკა

const int ldrPin = A1;        // LDR სენსორი უკავშირდება ანალოგურ პინ A0
const int lightledPin = 10;         // LED პინი


const int waterSensorPin = A0;

// LED-ების პინები
const int redLedPin = 8;
const int yellowLedPin = 7;
const int blueLedPin = 6;

// სერვოს პინი
const int servoPin = 9;
Servo myServo;

bool servoMoved = false; // ვაკონტროლოთ სერვოს მდგომარეობა

// LCD I2C პარამეტრები
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int gasSensorPin = 5;     // MQ სენსორის Digital Out
const int buzzerPin = 3;        // Passive ბაზერი
const int ledPin = 4;           // წითელი LED

// DHT სენსორი
#define DHTPIN 2        // სენსორი მიერთებულია პინზე 2
#define DHTTYPE DHT11   // თუ გაქვს DHT22, შეცვალე DHT22-ით

DHT dht(DHTPIN, DHTTYPE);



void setup() {
  pinMode(lightledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);         // მონიტორინგისთვის
  lcd.init();        
  lcd.backlight();   

  dht.begin();       // DHT სენსორის ინიციალიზაცია

  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000);
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);   // tone() მაინც საჭიროებს OUTPUT რეჟიმს
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);           // მონიტორინგისთვის

  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  myServo.attach(servoPin); // სერვოს მიერთება
  myServo.write(0);         // საწყის პოზიციაზე დაყენება

  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.println(lightValue);   // სანახავად მონიტორზე

  if (lightValue < 950) {
    digitalWrite(lightledPin, HIGH);     // აანთე ნათურა
    tone(buzzerPin, 1000);          // ჩართე ტონი
    delay(100);
    noTone(buzzerPin);              // გამორთე ტონი
    delay(00);
  } else {
    digitalWrite(lightledPin, LOW);      // ჩააქრე ნათურა
    noTone(buzzerPin);              // გამორთე ბაზერი
  }
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // ცელსიუსში

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000); // განახლება ყოველ 2 წამში
  int gasState = digitalRead(gasSensorPin);  // სენსორის მდგომარეობის წაკითხვა

  if (gasState == LOW) {
    // გაზი აღმოჩენილია
    tone(buzzerPin, 1000);         // ბაზერის ჩართვა (1000 ჰც ტონი)
    digitalWrite(ledPin, HIGH);    // ნათურის ჩართვა
    Serial.println("გაზი აღმოჩენილია!");
  } else {
    // ყველაფერი ნორმაშია
    noTone(buzzerPin);             // ბაზერის გამორთვა
    digitalWrite(ledPin, LOW);     // ნათურის გამორთვა
    Serial.println("ნორმალური მდგომარეობა");
  }

   int sensorValue = analogRead(waterSensorPin);

  Serial.print("Water Level: ");
  Serial.println(sensorValue);

  // LED ლოგიკა
  if (sensorValue < 200) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  } else if (sensorValue >= 200 && sensorValue < 300) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
  }

  // სერვოს ლოგიკა
  if (sensorValue < 150 && !servoMoved) {
    myServo.write(90);      // დაიტრიალოს
    servoMoved = true;
  } else if (sensorValue > 600 && servoMoved) {
    myServo.write(0);       // დაბრუნდეს საწყისზე
    servoMoved = false;
  }

  delay(1000); // განახლება ყოველ წამში
}
