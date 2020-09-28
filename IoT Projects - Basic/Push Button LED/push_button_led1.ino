int buttonState = 0;

void setup()
{
  pinMode(4, INPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // read the state of the pushbutton
  buttonState = digitalRead(4);
  // check if pushbutton is pressed. if it is, the
  // button state is HIGH
  if (buttonState == HIGH) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}