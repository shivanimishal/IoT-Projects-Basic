#define PIN_LED_1 	6
#define PIN_LED_2 	5
#define PIN_LED_3 	4
#define PIN_LED_4 	3
#define PIN_LED_5 	2
#define PIN_GAS 	A3

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(PIN_LED_5, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  
  int value = map(analogRead(PIN_GAS), 300, 750, 0, 100);
  digitalWrite(PIN_LED_1, value >= 20 ? HIGH : LOW);
  digitalWrite(PIN_LED_2, value >= 30 ? HIGH : LOW);
  digitalWrite(PIN_LED_3, value >= 40 ? HIGH : LOW);
  digitalWrite(PIN_LED_4, value >= 60 ? HIGH : LOW);
  digitalWrite(PIN_LED_5, value >= 80 ? HIGH : LOW);
  Serial.println(value);
  delay(10); // wait for a quarter second
}