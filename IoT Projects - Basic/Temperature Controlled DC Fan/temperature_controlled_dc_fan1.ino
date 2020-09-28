#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,8,7,6,5);
int tempPin = A0;   // Output pin for LM35
int fan = 10;       // pin for fan
int led = 6;        // pin for builtin indicator LED
int temp;
int tempMin = 30;   // fanspeed is minimum
int tempMax = 60;   // fanspeed is minimum
int fanSpeed;
int fanLCD;
int stop = 2;		// pin Interrupt 

void setup() {
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16,2);  

  pinMode(stop, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (stop), stopfan, HIGH); //digitalPinToInterrupt (stop), HIGH
}

void loop() {  
   temp = readTemp();     	 
   if(temp  < tempMin) { 	
      fanSpeed = 0; 		
      fanLCD=fanSpeed;
      digitalWrite(fan, LOW); 
   } 
   if((temp  >= tempMin) && (temp <= tempMax)) { 		// if temperature is higher than minimum temp 
      fanSpeed = map(temp, tempMin, tempMax, 32, 255);	// the actual speed of fan 
      fanLCD = map(temp, tempMin, tempMax, 0, 100); 	// speed of fan to display on LCD 
      analogWrite(fan, fanSpeed); 						// spin the fan at the fanSpeed speed 
   } 
   if(temp  > tempMax) {        
      fanSpeed = 0; 		 
      fanLCD=fanSpeed;
     digitalWrite(led, HIGH); 	 
   } else {                   	
     digitalWrite(led, LOW); 
   }
   
   lcd.print("TEMP: ");
   lcd.print(temp);      
   lcd.print("C ");
   lcd.setCursor(0,1);   
   lcd.print("FANS: ");
   lcd.print(fanLCD);    
   lcd.print("%");
   delay(200);
   lcd.clear();   
  
  
}

int readTemp() {  //temp in Celsius
  temp = analogRead(tempPin);
  return temp * 0.48828125;
}

void stopfan () {			
  lcd.clear();
  digitalWrite (fan, LOW);
  delayMicroseconds(90000000000000000000000);
  Serial.println("Stop");
  lcd.print("TEMP: --");
  lcd.setCursor(0,1); 
  lcd.print("FANS: 0%");
  
}
  