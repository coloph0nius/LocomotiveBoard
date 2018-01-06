#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFiUdp.h>

const char* ssid     = "LGB-Network";
const char* password = "bruno2017";
unsigned int udpPort = 4712;
unsigned int serverPort = 4711;
char incomingPacket[255];
char idPacket[] = "locomotive-packet;LCE";
char serverIP []= "192.168.10.1";
WiFiUDP Udp;
int _direction = 0;
int _speed = 0;



void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connecting to wifi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected!");
  delay (500);
  Udp.begin(udpPort);
  
  Udp.beginPacket(serverIP, serverPort);
  Udp.write(idPacket);
  Udp.endPacket();
  
  
}


void loop() 
{
  // put your main code here, to run repeatedly:
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.println(incomingPacket);
    char * results [2];
    char * pch;
    int i = 0;
    pch = strtok(incomingPacket, ";");
    while (pch != NULL)
    {
        results[i] = pch;
        pch = strtok (NULL, ";");
        i++;
    }
    _direction = atoi (results[0]);
    _speed = atoi (results[1]);
    setValues(_direction, _speed);
  } 
}

void setValues(int direction, int speed)
{
  Serial.println("called..");
  Serial.println(direction);
}
