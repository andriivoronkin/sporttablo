// Andrii Voronkin
//ESP-12
//tcp client
//git test 2
#include <ESP8266WiFi.h>
int result = 10;
//const char host [] = "127.1.1.1";
IPAddress server(192,168,4,1);
WiFiClient client;
void setup()
{
  Serial.println("Start");
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("console", "25252525");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

 

void loop() {

 
  // Use WiFiClient class to create TCP connections
  
  const int Port = 8888;
  delay (5000);
  Serial.print ("Connected ");
  Serial.println (server);
//  result = client.connect(server, Port);
//  Serial.println(result);
  if (!client.connect(server, Port))
  {
    Serial.println("connection failed");
  }
     
    if (client.connect(server, Port))
  {
    Serial.println("connection true");
  }
  }

