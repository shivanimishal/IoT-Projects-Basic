#include <LiquidCrystal.h>
#define trigPin1 6
#define trigPin2 7
#define trigPin3 8
#define echoPin1 6
#define echoPin2 7
#define echoPin3 8
#define led1 9
#define led2 10
#define led3 13
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  
  long readUltrasonicDistance(int triggerPin, int echoPin){
    pinMode(triggerPin, OUTPUT);  // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    return pulseIn(echoPin, HIGH);
  };

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
}
void loop() {
  float distance1;
  float distance2;
  float distance3;
  lcd.setCursor(0, 0);
  lcd.print("All Slots empty");

   distance1 = (readUltrasonicDistance(6, 6) * 0.034)/2;
   Serial.println(distance1);
   if (distance1 >=320|| distance1 <= 2){
    digitalWrite(led1, HIGH);
  }
  else {
    digitalWrite(led1, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 filled");
    delay(2000);
  }
    distance2 = (readUltrasonicDistance(7, 7) * 0.034)/2;
   if (distance2 >=320 || distance2 <= 2){
    digitalWrite(led2, HIGH);
  }
  else {
    digitalWrite(led2, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slot 2 filled");
    delay(2000);
  }
    distance3 = (readUltrasonicDistance(8, 8) * 0.034)/2;
   if (distance3 >=320 || distance3 <= 2){
    digitalWrite(led3, HIGH);
    delay(500);
  }
  else {
    digitalWrite(led3, LOW);
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Slot 3 filled");
    delay(2000);
  }
  
lcd.clear();
delay(50);
  /*lcd.setCursor(0,0);
  lcd.print("Hello");
  delay(1000);
  lcd.clear();
  delay(50);*/
}

