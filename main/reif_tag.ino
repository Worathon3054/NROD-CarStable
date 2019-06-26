#include <MFRC522.h>
#include <RTClib.h>
#include <time.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

struct Address{
  int Num0;
  int Num1;
  int Num2;
  int Num3;
}IDCARD,Car1,Car2; 

void RFID_TAG() {
   SPI.begin();       // Init SPI bus
   mfrc522.PCD_Init(); // Init MFRC522
   pinMode(LED_BUILTIN, OUTPUT);
   configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
   while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
   Serial.println("\nRFID reading UID");
}

void RFID_Taging() {
  
  Car1.Num0 = 55, Car1.Num1 = 33, Car1.Num2 = 214, Car1.Num3 = 115;
  Car2.Num0 = 83, Car2.Num1 = 248, Car2.Num2 = 127, Car2.Num3 = 99;
  
  if ( mfrc522.PICC_IsNewCardPresent()){
      if ( mfrc522.PICC_ReadCardSerial()){
          IDCARD.Num0=mfrc522.uid.uidByte[0];
          IDCARD.Num1=mfrc522.uid.uidByte[1];
          IDCARD.Num2=mfrc522.uid.uidByte[2];
          IDCARD.Num3=mfrc522.uid.uidByte[3];
      }
  }
  while(Car1.Num0 == IDCARD.Num0 && Car1.Num1 == IDCARD.Num1 && Car1.Num2 == IDCARD.Num2 && Car1.Num3 == IDCARD.Num3){
        int i = 1;
        Serial.println("Car1 : Succeed");
        IDCARD.Num0 = 0,IDCARD.Num1 = 0, IDCARD.Num2 = 0,IDCARD.Num3 = 0;
        while(i==1){
            time_t now = time(nullptr);
            struct tm* p_tm = localtime(&now);
            Serial.print("Date : ");
            Serial.print(p_tm->tm_mday),Serial.print("/"),Serial.print(p_tm->tm_mon + 1),Serial.print("/"),Serial.print(p_tm->tm_year + 1900);
            Serial.print("   Time : ");
            Serial.print(p_tm->tm_hour),Serial.print(":"),Serial.print(p_tm->tm_min),Serial.print(":"),Serial.print(p_tm->tm_sec);
            Serial.print("\n");
            i=0;
        }
        digitalWrite(LED_BUILTIN, HIGH);
        delay(3000);
        digitalWrite(LED_BUILTIN, LOW);
  }while(Car2.Num0 == IDCARD.Num0 && Car2.Num1 == IDCARD.Num1 && Car2.Num2 == IDCARD.Num2 && Car2.Num3 == IDCARD.Num3){
        int i = 1;
        Serial.println("Car2 : Succeed");
        IDCARD.Num0 = 0,IDCARD.Num1 = 0, IDCARD.Num2 = 0,IDCARD.Num3 = 0;
        while(i==1){
            time_t now = time(nullptr);
            struct tm* p_tm = localtime(&now);
            Serial.print("Date : ");
            Serial.print(p_tm->tm_mday),Serial.print("/"),Serial.print(p_tm->tm_mon + 1),Serial.print("/"),Serial.print(p_tm->tm_year + 1900);
            Serial.print("   Time : ");
            Serial.print(p_tm->tm_hour),Serial.print(":"),Serial.print(p_tm->tm_min),Serial.print(":"),Serial.print(p_tm->tm_sec);
            Serial.print("\n");
            i=0;
        }
        digitalWrite(LED_BUILTIN, HIGH);
        delay(3000);
        digitalWrite(LED_BUILTIN, LOW);
  }
}
