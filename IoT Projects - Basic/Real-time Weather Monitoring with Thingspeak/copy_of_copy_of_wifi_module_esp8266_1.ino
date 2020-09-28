float temperature; //variable temperature (degree Celsius)
float vout; //temporary variable sensor reading
float vout1;
int LED = 12;
int sensor_Input;

String ssid     = "Simulator Wifi";  // SSID to connect to
String password = ""; // Our virtual wifi has no password (so dont do your banking stuff on this network)
String host     = "api.thingspeak.com"; // website name API
const int httpPort   = 80;
// provide your API key below in between thr '=' sign and '&' sign
String uri     = "/update?api_key=F7CUORX55BRBTANL&field1=";

int setupESP8266(void) {
  // Start our ESP8266 Serial Communication
  Serial.begin(115200);   // Serial connection over USB to computer
  Serial.println("AT");   // Serial connection on Tx / Rx port to ESP8266
  //AT - Attention test at startup
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 1;
    
  // Connect to 123D Circuits Simulator Wifi
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  //AT+CWJAP = "ssid","password" //Join network (set) 
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 2;
  
  // Open TCP connection to the host:
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  // AT+CIPSTART=<type>,<addr>,<port> - Connect to socket server 
  delay(50);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 3;
  
  return 0;
}

void postData(int temperature, int ledstatus, int sensor_Input)
{
  String httpPacket;
 // Construct our HTTP call
   httpPacket = "GET " + uri + String(temperature)  + "&field2=" + String(ledstatus) + "&field3=" + String(sensor_Input)+" HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();
  // Send our message length
  Serial.print("AT+CIPSEND="); 
  //execute Send data. For unvarnished transmission mode.
  Serial.println(length);
  delay(100);
  
  // Send our http request
  Serial.print(httpPacket);
  delay(10);
   if (!Serial.find("SEND OK\r\n")) return;
}
void setup() {
  setupESP8266();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  vout=analogRead(A0); //Reading the value from sensor

//analogReference(DEFAULT);
//// convert analog values between 0 and 1023 with 5000mV/5V ADC
  vout1 = (vout/1023) * 5000;
  
  temperature=(vout1-500)/10;
  sensor_Input=analogRead(A1);
  
  //int temperature = map(analogRead(A0),-40,110,0,90);
  if (temperature>=80) 
  {
    digitalWrite(LED,HIGH);
      postData(temperature,1,sensor_Input);
  }
  else
  {
    digitalWrite(LED,LOW);
      postData(temperature,0,sensor_Input);
  }
  //send data to thingspeak
  delay(10000);
}

