#define sclk 14
#define mosi 13
#define cs   15
#define dc   2
#define rst  16
int dip;


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

void setup() {
  finger.begin((uint64_t)115200);
}

void loop() {

  int result;
 finger.ToggleLed(true);
 delay(1000);
 result = finger.Enroll_into_memory();
 delay(3000);
 dip = finger.Identify();
    tft.fillScreen(ST7735_BLACK);
    Serial.println("Hello message");
    tft.setTextSize(3);
    tft.setCursor(0, 10);
    tft.setTextColor(ST7735_WHITE);
    tft.println("Your Template");
    tft.println("");
    tft.setTextSize(1);
    tft.println(dip);
    delay(3000);
  while(true){
    
  }

}
