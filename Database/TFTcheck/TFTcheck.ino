#define sclk 14
#define mosi 13
#define cs   15
#define dc   2
#define rst  16
bool dip;


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);
//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

void setup() {

  tft.initR(INITR_BLACKTAB);
}

void loop() {

  tft.fillScreen(ST7735_BLACK);
  int result;
  bool ya = true;
  finger.ToggleLed(ya);
  delay(2000);
  result = finger.Enroll_into_memory();
  dip = finger.Identify();
  if (dip) {
    tft.fillScreen(ST7735_BLACK);
    Serial.println("Hello message");
    tft.setTextSize(3);
    tft.setCursor(0, 10);
    tft.setTextColor(ST7735_WHITE);
    tft.println(" APECE");
    tft.println("");
    tft.setTextSize(1);
    tft.print("     5th Semester");
    delay(3000);
  }
}
