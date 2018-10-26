/*
    This sketch sends a message to a TCP server

*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <string.h>
#include <SPI.h> //библиотека spi//


// leds fragments
#define S0 (1<<0)
#define S1 (1<<1)
#define S2 (1<<2)
#define S3 (1<<3)
#define S4 (1<<4)
#define S5 (1<<5)
#define S6 (1<<6)
#define S7 (1<<7)

static uint8_t out_symbol[10] = {S0 | S1 | S2 | S3 | S4 | S5, S1 | S2, S0 | S1 | S3 | S4 | S6, S0 | S1 | S2 | S3 | S6, S1 | S2 | S5 | S6,
                                 S0 | S2 | S3 | S5 | S6, S0 | S2 | S3 | S4 | S5 | S6, S0 | S1 | S2, S0 | S1 | S2 | S3 | S4 | S5 | S6, S0 | S1 | S2 | S3 | S5 | S6
                                };

ESP8266WiFiMulti WiFiMulti;
WiFiClient client; // Use WiFiClient class to create TCP connections

const uint16_t port = 8888;
const char * host = "192.168.4.1"; // ip or dns

//data
int period1 = -1;
int period2 = -1;
char period3 = -1;
String line;
char bufer[70];
int Period;
int OldPeriod;
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

const int ss = 5; // защелка
const int led = 2 ;  // OE for esp-12
byte voidNumber = B00000000;


void setup() {

  Serial.begin(115200);
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);

  pinMode(ss, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);
  digitalWrite(ss, HIGH);
  delay(2);
  Serial.println("Start");

  //*************************************
  //We start by connecting to a WiFi network

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("console", "25252525");
  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED)
  {
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




  if (!client.connect(host, port))
  {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }
  if (client.connected())
  {
    Serial.println("host connected");
  }
}


void loop() {

  int  checkConection = client.connected();
 
  switch (checkConection)
  {
    case 0:
      if (WiFiMulti.run() != WL_CONNECTED)
      {
        checkConection = 2;
      }

      Serial.println("client stop");
      client.stop();
      Serial.println("wait reconection");
      delay (5000);

      while (WiFiMulti.run() != WL_CONNECTED)
      {
        Serial.print(".");
        delay(500);
      }

      client.connect(host, port);
      delay(500);
      Serial.println(client.connected());
      break;
    case 1:

      if (WiFiMulti.run() != WL_CONNECTED)
      {
        checkConection = 2;
        break;
      }

//      while (!client.available()) {
//        delay(100);
//        Serial.print(".");
//        break;
//      }
      
      if (client.available())
      {
        line = client.readStringUntil('$');
        Serial.println(line);
        line.toCharArray(bufer, 51);
        Period = atoi(strtok(bufer, " "));
        Serial.print("Period = ");
        Serial.println(Period);

        if (OldPeriod != Period)
        {
          SpiSend(Period);
          OldPeriod = Period;
        }

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
      }



      if (!client.connected()) {
        Serial.println("host disconnected");
      }
      break;

    case 2:

      Serial.println("WiFi disconnected");
      Serial.println("reconnecting");
      while (WiFiMulti.run() != WL_CONNECTED)
      {
        Serial.print(".");
        delay(500);
      }

      delay (500);
      client.connect(host, port);
      delay(500);
      Serial.println(client.connected());
      break;
  }
}

