#define trigPin  A0         // Assign PIN A0 as trigPin (Connect ARDUINO UNO "A0" pin with Ultrasonic Sonar Sensor "TRIG" Pin) 
#define echoPin  A1         // Assign PIN A1 as echoPin (Connect ARDUINO UNO "A1" pin with Ultrasonic Sonar Sensor "ECHO" Pin) 
int motorA1=9;
int motorA2=10;
int motorEN=11;
int buzzervcc=13;
int count;
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
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT); 
    pinMode(motorA1,OUTPUT);
    pinMode(motorA2,OUTPUT);
    pinMode(buzzervcc,OUTPUT);
    digitalWrite(buzzervcc,HIGH);
    Serial.begin(9600);
}
void loop() { 
  float motorspeed;
  motorspeed= 255;
  analogWrite(motorEN, motorspeed);
  float cm=search();

  if(cm<24){
       motorstop();
       Serial.print("High ");
       Serial.println(cm);
       delay(300);
   }
   else if(cm>24 && cm<40 && count==1){
        motorstop();
        //motorforward();
        Serial.print("Medium ");
        Serial.println(cm);
        delay(300);
   }
   else{
       while(1){
       cm=search();
       if(cm<24)
       break;
       motorforward();
       Serial.print("LOW ");
       Serial.println(cm);
       count=1;
       delay(300);
    }
  }
}
