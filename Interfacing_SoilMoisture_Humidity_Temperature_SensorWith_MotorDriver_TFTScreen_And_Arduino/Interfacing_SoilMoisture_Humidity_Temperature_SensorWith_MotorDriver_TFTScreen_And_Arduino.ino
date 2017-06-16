/*
   Author: Towqir Ahmed Shaem
   Department : Applied Physics, Electronics and Communication Engineering,CU
   Company : Stellarbd, CDA Avenue, Chittagong, 4000, Bangladesh
   Postion : Sub Junior Embedded System Software Engineer
   Mobile : 01521401124
   Email : tpwqirahmedshaem@gmail.com
   Git : https://gitlab.com/Shaem
*/

#include "DHT.h"
#include <Adafruit_GFX.h>
#include "SPI.h"
#include "Adafruit_ST7735.h"

#define TFT_vcc 6
#define TFT_led 0
#define TFT_CS A1
#define TFT_RST A2
#define TFT_DC  A3
#define TFT_SDA 11
#define TFT_SCK 13
DHT dht;
#define soilinput A0
#define soilvcc 12
#define motorenable 3
#define motorin1 10
#define motorin2 9
#define motorenableb 6
#define motorin3 4
#define motorin4 5
#define tempinput 8
#define tempvcc 7

int data;
int tempdata;
float mv;
float temperature;
int block = 0;
int tempblock = 0;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  pinMode(tempinput, INPUT);
  pinMode(motorin1, OUTPUT);
  pinMode(motorin2, OUTPUT);
  pinMode(motorin3, OUTPUT);
  pinMode(motorin4, OUTPUT);
  pinMode(tempvcc, OUTPUT);
  pinMode(soilvcc, OUTPUT);
  pinMode(soilinput, INPUT);
  digitalWrite(soilvcc, HIGH);
  digitalWrite(tempvcc, HIGH);
  
  Serial.begin(9600);
  dht.setup(tempinput); 

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLUE);
  tft.setTextSize(2);
  tft.setCursor(30,40);
  tft.println("WELCOME");
  delay(1000);
  tft.fillScreen(ST7735_BLUE);
  tft.setTextSize(1);
  tft.setCursor(10, 10);
  tft.println("  TOWQIR AHMED SHAEM\n");
  tft.println("         APECE,CU\n");
  tft.println("   SUB JUNIOR ENGINEER\n");
  tft.println("  STELLARBD, CHITTAGONG\n");
  tft.println("   https://gitlab/Shaem\n");
  tft.println("       01521401124\n");
  tft.println("towqirahmedshaem@gmail.com\n");
  delay(10000);

}

void loop()
{
  /*
     SOIL Sensor Reading..
     Very High- 320
     High- 340
     Medium- 365
     Low- 400
     Very Low- 600
  */
 
  delay(dht.getMinimumSamplingPeriod());
  Serial.println("----------------------------------------------------------------------");
  Serial.println("Status\tHumidity (%)\tTemperature (C)\tTemperature (F)\tSoil Mooisture");

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  data = analogRead(soilinput);

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.print(dht.toFahrenheit(temperature), 1);
  Serial.print("\t\t");
  Serial.println(data);
  Serial.println("----------------------------------------------------------------------");

  tft.fillScreen(ST7735_BLUE);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(0,5);
  tft.println("--------------------------");
  tft.println("           DATA");
  tft.println("--------------------------");
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(0,40);
  tft.print(" HUMIDITY : ");
  tft.println(humidity);
  tft.println();
  tft.print(" TEMPERATURE (C): ");
  tft.println(temperature);
  tft.println();
  tft.print(" TEMPERATURE (F): ");
  tft.println(dht.toFahrenheit(temperature));
  tft.println();
  tft.print(" SOIL MOISTURE : ");
  tft.println(data);
  tft.println();
  tft.println("      ----- * -----");
  delay(3000);


  if (temperature < 25) {
    /*
       Temperatue is very LOW
       AC Stop
    */
    Serial.println("Temperature is Very LOW");
    Serial.println("AC OFF");
    analogWrite(motorenableb, 0);
    tempblock = 0;
    delay(300);
  }
  if (temperature > 25 && temperature < 35 && tempblock == 1) {
    /*
       Temmperature is Medium Level
       AC ON but Medium Speed
    */
    Serial.println("Temperature is Medium Level");
    Serial.println("AC ON, Medium Speed");
    analogWrite(motorenableb, 180);
    digitalWrite(motorin3, HIGH);
    digitalWrite(motorin4, LOW);
    delay(300);
  }
  if (temperature > 35) {
    /*
       Temperature is very HIGH
       AC ON
    */
    Serial.println("Temperature is Very High");
    Serial.println("AC ON , High Speed");
    analogWrite(motorenableb, 255); // Full speed
    digitalWrite(motorin3, HIGH);
    digitalWrite(motorin4, LOW);
    delay(300);
    tempblock = 1;
  }

  if (data <= 320 ) {
    /* This function is used for turing on the motor to decrease water level */
    Serial.println("Soil Moisture Is Very High");
    Serial.println("Motor on to decrease the water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, LOW);
    digitalWrite(motorin2, HIGH);
    delay(800);
    block = -1;
  }
  else if (data > 320 && data < 360 && block == -1) {
    /*
    */
    Serial.println("Soil Moisture High Level");
    Serial.println("Motor on to decrease the water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, LOW);
    digitalWrite(motorin2, HIGH);
    delay(800);

  }
  else if (data >= 370 && data <= 450) {
    /*
       Motor Stop,Because water level is good
    */
    Serial.println("Soil Moisture Is At Room Moisture Level");
    Serial.println("Motor Stop ");
    analogWrite(motorenable, 0);
    delay(800);
    block = 0;
  }
  else if (data <= 600 && data >= 450 && block == 1) {
    /*
       Low
    */
    Serial.println("Soil Moisture is Low");
    Serial.println("Motor on to increase water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, HIGH);
    digitalWrite(motorin2, LOW);
    delay(800);
  }
  else if (data >= 600) {
    /*
       Very low
    */
    Serial.println("Soil Moisture is Very Low");
    Serial.println("Motor on to increase water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, HIGH);
    digitalWrite(motorin2, LOW);
    delay(800);
    block = 1;
  }
  Serial.println();
  Serial.println();
  Serial.println();
}
