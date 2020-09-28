/*
 * PIR sensor tester
 */
 
int ledPin = 13;  
int nxtPinA = 11;
int nxtPinB = 9;  // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 2;  
int piezoPin = 12;
          //Variable to store analog value (0-1023)
  // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT); 
  pinMode(nxtPinA, OUTPUT);
  pinMode(nxtPinB, OUTPUT);// declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);

}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);
    digitalWrite(nxtPinA, HIGH);
    digitalWrite(nxtPinB, HIGH);
    digitalWrite(ledPin, HIGH);
    tone(piezoPin, 1000, 500);
    // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
  
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
