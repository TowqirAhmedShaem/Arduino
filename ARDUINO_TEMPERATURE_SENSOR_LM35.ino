/*
 Developer : Towqir Ahmed Shaem
 Institute : Appplied Physics, Electronics and Communication Engineering, Chittagong University.
 Email : towqirahmedshaem@gmail.com
 */
int value;
int tempPin =A0;
int motorA1=9;
int motorA2=10;
int motorEN=11;

void setup()
{
 pinMode(tempPin,INPUT);
 pinMode(motorA1,OUTPUT);
 pinMode(motorA2,OUTPUT);
 Serial.begin(9600);
}

void motorforward()
  {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  }
void motorstop()
  {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  }

void loop()
{
value = analogRead(tempPin);
float mv =(5.0 * 1000.0 * value ) / 1024;    // It is the equation to find the value in mV. Here 5 is our  given voltage.
float celcius = mv/10;                       // 10mV is equal to 1 degree Celcius
float farenhite  = (celcius*9)/5 + 32;
Serial.print("TEMPRATURE = ");
Serial.print(celcius);
Serial.print("*C    ");
Serial.print(farenhite );
Serial.print("*F");
Serial.println();
//delay(1000);
 if(celcius<25){
      motorstop(); // or analogWrite(motorEN, 0);
   }
 else if(celcius>25 && celcius < 40){
   analogWrite(motorEN, 150);
   motorforward();
   }
 else{
   analogWrite(motorEN, 255); // Full speed
   motorforward();
}
}
