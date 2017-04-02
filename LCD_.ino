#include <LiquidCrystal.h> // includes the LiquidCrystal Library 

LiquidCrystal lcd1(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

#define trigPin  A0         // Assign PIN A0 as trigPin (Connect ARDUINO UNO "A0" pin with Ultrasonic Sonar Sensor "TRIG" Pin) 
#define echoPin  A1         // Assign PIN A1 as echoPin (Connect ARDUINO UNO "A1" pin with Ultrasonic Sonar Sensor "ECHO" Pin) 
int motorA1=9;
int motorA2=10;
int motorEN=11;
int buzzervcc=13;


float search(void)
  {
    float duration = 0.00;                // Float type variable declaration 
    float CM = 0.00;
      
      
      digitalWrite(trigPin, LOW);        // Trig_pin output as OV (Logic Low-Level) 
      delayMicroseconds(2);              // Delay for 2 us
    
      //Send 10us High Pulse to Ultra-Sonic Sonar Sensor "trigPin" 
      digitalWrite(trigPin, HIGH);       // Trig_pin output as 5V (Logic High-Level)
      delayMicroseconds(10);             // Delay for 10 us 
    
      digitalWrite(trigPin, LOW);        // Trig_pin output as OV (Logic Low-Level)
  
    
    duration = pulseIn(echoPin, HIGH); // Start counting time, upto again "echoPin" back to Logical "High-Level" and puting the "time" into a variable called "duration" 
   
    CM = (duration / 58.82); //Convert distance into CM. 
    
   return CM;
  }

  void motorforward()
  {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  }

  void motorbackward()
  {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  }
  void motorstop()
  {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  }

  
void setup() { 
    lcd1.begin(16,2);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT); 
    pinMode(motorA1,OUTPUT);
    pinMode(motorA2,OUTPUT);
    pinMode(buzzervcc,OUTPUT);
    digitalWrite(buzzervcc,HIGH);
}
void loop() { 
  float motorspeed;
  motorspeed= 255;
  analogWrite(motorEN, motorspeed);
  float cm=search();
  lcd1.setCursor(0,0);
  lcd1.print("Distance: ");
  lcd1.print(cm);
  delay(500);
  lcd1.setCursor(3,1);
  if(cm<10){
       motorstop();
       lcd1.print("Level: HIGH  ");
       delay(300);
       lcd1.clear();
   }
   else if(cm>10 && cm<40){
        motorstop();
        lcd1.print("Level: MEDIUM");
        delay(300);
   }
   else{
        lcd1.print("Level: LOW   ");
        motorforward();
      // motorbackward();
        delay(800);
  }
}
