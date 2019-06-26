//LCD  SDA - D3 SCL - D1
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#define SCREEN_WIDTH 128 
//#define SCREEN_HEIGHT 32 

void timesetup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  display.setCursor(0,0);

  display.display();

  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  display.println("\nWaiting for NTP...");

  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  display.println("\nTime response....OK"); 
  display.display();  
  delay(1000);

  display.clearDisplay();
  display.display();
}

void timeloop() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  // Clear the buffer.
  display.clearDisplay();
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  Serial.print(" \n");
  
  display.setCursor(0,0);
  display.print(p_tm->tm_hour);
  display.print(":");
  if( p_tm->tm_min <10)
    display.print("0"); 
  display.print(p_tm->tm_min);
  
  display.setTextSize(1);
  display.setCursor(30,0); // วินาที
  display.print(".");
  if( p_tm->tm_sec <10)
    display.print("0"); 
  display.print(p_tm->tm_sec);

  display.setTextSize(1);
  display.setCursor(0,40);
  display.print(p_tm->tm_mday);
  display.print("/");
  display.print(p_tm->tm_mon + 1);
  display.print("/");
  display.print(p_tm->tm_year + 1900);

  display.display();

  delay(1000); // update every 1 sec
}
