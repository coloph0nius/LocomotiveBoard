#include <ESP8266WiFi.h>
#include <ESP_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>

const char* ssid     = "wlan";
const char* password = "password";


void setup() 
{
  Serial.begin(115200);
  Serial.println("Connecting to wifi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
