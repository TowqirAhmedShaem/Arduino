//#include <TFT.h>  // Arduino LCD library
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);
#include <SPI.h>
#define cs   15
#define dc   12
#define rst  13
bool dip;
// create an instance of the library

Adafruit_ST7735 TFTscreen = Adafruit_ST7735(cs, dc, rst);

// char array to print to the screen
int val = 0;  

void setup() {
      finger.begin((uint64_t)115200);
  Serial.begin(9600);
  //TFTscreen.begin();
 // TFTscreen.background(0, 0, 0);
 TFTscreen.fillScreen(ST7735_WHITE);
  // write the static text to the screen
  // set the font color to white
//  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.setCursor(1,0);
  TFTscreen.setTextColor(ST7735_BLACK);
  TFTscreen.print("WELCOME!!  ");
  delay(3000);
  TFTscreen.setCursor(1,3);
  TFTscreen.print("APECE, CU ");
  TFTscreen.setTextSize(5);
  delay(3000);
}

void loop() {
   Serial.begin(9600);
  //TFTscreen.begin();
 // TFTscreen.background(0, 0, 0);
 TFTscreen.fillScreen(ST7735_WHITE);
  // write the static text to the screen
  // set the font color to white
//  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.setCursor(1,0);
  TFTscreen.setTextColor(ST7735_BLACK);
  TFTscreen.print("WELCOME!!  ");
  delay(3000);
  TFTscreen.setCursor(1,3);
  TFTscreen.print("APECE, CU ");
  TFTscreen.setTextSize(5);
  delay(3000); 
  finger.Enroll_into_memory();
  dip=finger.Identify();
  
  }

