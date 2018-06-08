/*
    This sketch sends a message to a TCP server

*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <string.h>

ESP8266WiFiMulti WiFiMulti;

// Use WiFiClient class to create TCP connections
WiFiClient client;

const uint16_t port = 8888;
const char * host = "192.168.4.1"; // ip or dns
int period1 = -1;
int period2 = -1;
char period3 = -1;
String line;
char bufer[70];
int Period;
int LeftTimeout;
int RightTimeout;
int Minute;
String PeriodStr;

int LeftPart1;
int RightPart1;

//*****//
int LeftPart2;
int RightPart2;

//*****//
int LeftPart3;
int RightPart3;

//*****//
int LeftPart4;
int RightPart4;


void setup() {
  Serial.begin(9600);
  delay(10);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("console", "25252525");

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);

  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }
  if (client.connected()) {
    Serial.println("host connected");
  }

}


void loop() {

  //read back one line from server
  Serial.println("read data from host");

  //  if (client.available()) {
  //    char c = client.read();
  //    Serial.print(c);
  //  }

  while (!client.available()) {
    delay(1);
  }
  if (client.available())
  {
    line = client.readStringUntil('$');
    Serial.println(line);
  }

  line.toCharArray(bufer, 51);
  Period = atoi(strtok(bufer, " "));
  Serial.print("Period = ");
  Serial.println(Period);
  
  LeftTimeout = atoi(strtok(NULL, " "));
  RightTimeout = atoi(strtok(NULL, " "));
  Serial.print(RightTimeout);
  Serial.print("-Timeout-");
  Serial.println(LeftTimeout);
  
  LeftPart1 = atoi(strtok(NULL, " "));
  RightPart1 = atoi(strtok(NULL, " "));
  Serial.print(LeftPart1);
  Serial.print("-Part1-");
  Serial.println(RightPart1);
  
  LeftPart2 = atoi(strtok(NULL, " "));
  RightPart2 = atoi(strtok(NULL, " "));
  Serial.print(LeftPart2);
  Serial.print("-Part2-");
  Serial.println(RightPart2);
  
  LeftPart3 = atoi(strtok(NULL, " "));
  RightPart3 = atoi(strtok(NULL, " "));
  Serial.print(LeftPart3);
  Serial.print("-Part3-");
  Serial.println(RightPart3);  
  
  LeftPart4 = atoi(strtok(NULL, " "));
  RightPart4 = atoi(strtok(NULL, " "));
  Serial.print(LeftPart4);
  Serial.print("-Part4-");
  Serial.println(RightPart4);
  
  Minute = atoi(strtok(NULL, " "));
  Serial.print("Minute = ");
  Serial.println(Minute);

  if (!client.connected()) {
    Serial.println("host disconnected");
    client.stop();
    delay (5000);

    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      Serial.println("wait 5 sec...");
      delay(5000);
      return;
    }
  }

}

