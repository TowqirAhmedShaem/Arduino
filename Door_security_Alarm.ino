#define trigPin  A1        // Assign PIN A0 as trigPin (Connect ARDUINO UNO "A0" pin with Ultrasonic Sonar Sensor "TRIG" Pin) 
#define echoPin  A0         // Assign PIN A1 as echoPin (Connect ARDUINO UNO "A1" pin with Ultrasonic Sonar Sensor "ECHO" Pin) 
int buzzervcc=11;
int distance;
void buzzerbling(){
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
  analogWrite(buzzervcc,255);
  delay(200);
  analogWrite(buzzervcc,0);
  delay(200);
}
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
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzervcc,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance=search();
  delay(300);
  Serial.print("Diatance : ");
  Serial.println(distance);
  Serial.println(distance);
  if(distance<30)
  {
    Serial.println("Someone enters");
    buzzerbling();
  }

}
