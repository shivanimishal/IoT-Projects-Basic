int r1=1;
int y1=2;
int g1=3;
int r2=4;
int y2=5;
int g2=6;
void setup() 
{
pinMode(r1,OUTPUT);
pinMode(y1,OUTPUT);
pinMode(g1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(y2,OUTPUT);
pinMode(g2,OUTPUT);
}

void loop() 
{
digitalWrite(g1,HIGH);
digitalWrite(r2,HIGH);
delay(10000);
digitalWrite(r1,LOW);
digitalWrite(y1,LOW);
digitalWrite(y2,LOW);
digitalWrite(g2,LOW);

digitalWrite(g1,LOW);  
digitalWrite(y1,HIGH);
digitalWrite(y2,HIGH);
delay(5000);
digitalWrite(y1,LOW);
digitalWrite(y2,LOW);
digitalWrite(r1,LOW);
digitalWrite(r2,LOW);
digitalWrite(g2,LOW);

digitalWrite(r1,HIGH);
digitalWrite(g2,HIGH);
delay(10000);
digitalWrite(r1,LOW);
digitalWrite(g2,LOW);
digitalWrite(y1,LOW);
digitalWrite(g1,LOW);
digitalWrite(r2,LOW);
digitalWrite(y2,LOW);

}