/*
   Author: Towqir Ahmed Shaem
   Department : Applied Physics, Electronics and Communication Engineering,CU
   Company : Stellarbd, CDA Avenue, Chittagong, 4000, Bangladesh
   Postion : Sub Junior Embedded System Software Engineer
   Mobile : 01521401124
   Email : tpwqirahmedshaem@gmail.com
   Git : https://gitlab.com/Shaem
*/
#define soil A0
#define motorenable 11
#define motorin1 10
#define motorin2 9
#define motorenableb 5
#define motorin3 6
#define motorin4 7
#define tempinput A5
#define tempvcc 12
int data;
int tempdata;
float mv;
float celcius;
int block = 0;
int tempblock = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(motorin1, OUTPUT);
  pinMode(motorin2, OUTPUT);
  pinMode(motorin3, OUTPUT);
  pinMode(motorin4, OUTPUT);
  pinMode(tempvcc, OUTPUT);
  pinMode(tempinput, INPUT);
  digitalWrite(tempvcc, HIGH);
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
  tempdata = analogRead(tempinput);
  Serial.println(tempdata);
  mv = (5.0 * 1000.0 * tempdata ) / 1024;   // It is the equation to find the value in mV. Here 5 is our  given voltage.
  celcius = mv / 10;                     // 10mV is equal to 1 degree Celcius
  Serial.print("Temperature : ");
  Serial.print(celcius);
  Serial.println(" Celcius");

  data = analogRead(A0);
  Serial.println(data);
  delay(300);

  if (celcius < 25) {
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
  if (celcius > 25 && celcius < 35 && tempblock == 1) {
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
  if (celcius > 35) {
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
    Serial.println("Very High");
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
    Serial.println("High Level");
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
    Serial.println("Motor Stop ");
    analogWrite(motorenable, 0);
    delay(800);
    block = 0;
  }
  else if (data <= 600 && data >= 450 && block == 1) {
    /*
       Low
    */
    Serial.println("Low");
    Serial.println("Motor on to increase water level");
    Serial.println("Motor on to decrease the water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, HIGH);
    digitalWrite(motorin2, LOW);
    delay(800);
  }
  else if (data >= 600) {
    /*
       Very low
    */
    Serial.println("Very Low");
    Serial.println("Motor on to increase water level");
    Serial.println("Motor on to decrease the water level");
    analogWrite(motorenable, 255);
    digitalWrite(motorin1, HIGH);
    digitalWrite(motorin2, LOW);
    delay(800);
    block = 1;
  }
}
