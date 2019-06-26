#include <SPI.h>
#include <EEPROM.h>
#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>

#define SS_PIN D4
#define RST_PIN D2

#define OLED_RESET D4  //4
Adafruit_SSD1306 display(OLED_RESET);

int ledPin = 13;
int timezone = 7 * 3600;
int dst = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  WiFiConnections();
  RFID_TAG();
}

void loop() {
  RFID_Taging();
}
