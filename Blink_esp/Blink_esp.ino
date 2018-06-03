/*
    This sketch sends a message to a TCP server

*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

// Use WiFiClient class to create TCP connections
WiFiClient client;

const uint16_t port = 8888;
const char * host = "192.168.4.1"; // ip or dns

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


  if(client.available()){
    String line = client.readStringUntil('$');
    Serial.println(line);
  }
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
  
  delay(2000);

}

