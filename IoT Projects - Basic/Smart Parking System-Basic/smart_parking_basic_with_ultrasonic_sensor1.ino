float distth=350;
float cm=0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
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
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
 cm= 0.01723 * readUltrasonicDistance(7, 7);
  if(cm>distth)
  {
    digitalWrite(13, LOW);
    noTone(6);
  }
  if(cm<=distth && cm>distth-100)
  {
    digitalWrite(13, HIGH);
    tone(6, 500, 150);
    delay(1000);
    digitalWrite(13, LOW);
    noTone(6);
    delay(1000);
  }
  if(cm<=distth-100 && cm>distth-250)
  {
    digitalWrite(13, HIGH);
    tone(6, 700, 250);
    delay(1000);
    digitalWrite(13, LOW);
    noTone(6);
    delay(1000);
  }
  if(cm<=distth-250 && cm>distth-350)
  {
    digitalWrite(13, HIGH);
    tone(6, 900, 350);
  }
}