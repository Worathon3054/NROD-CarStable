#include <ESP8266WiFi.h>

const char* ssid     = "IT@WIFI";
const char* password = "itnrodegat";

void WiFiConnections() {
   Serial.println("Starting...");

   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
      delay(250);
      Serial.print(".");
   }
   Serial.println("\nWiFi connected");  
   Serial.print("IP address: ");
   Serial.print(WiFi.localIP());
   
}
