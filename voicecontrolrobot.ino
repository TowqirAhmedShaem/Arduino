#include <Servo.h>
#define trig A0
#define echo A1
int motorleft1 = 5;
int motorleft2 = 6;
int motorright1 = 7;
int  motorright2 = 8;
int  motorleftenb = 9;
int motorrightenb = 10;
int pos = 0;
String data;
int command ;
int x;
float distance;
Servo myservo;
Servo myservo2;
Servo myservo3;
float sending() {
  float duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = duration / 58.82;
  return cm;
}
void setup() {
  pinMode(motorleft1, OUTPUT);
  pinMode(motorleft2, OUTPUT);
  pinMode(motorright1, OUTPUT);
  pinMode(motorright2, OUTPUT);
  pinMode(motorleftenb, OUTPUT);
  pinMode(motorrightenb, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(11);
  myservo2.attach(12);
  myservo3.attach(13);
  Serial.begin(9600);
}
void robotforward() {
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW);
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
}
void robotbackward() {
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, HIGH);
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, HIGH);
}
void robotleft() {
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, HIGH);
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
}
void robotright() {
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW);
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, HIGH);
}
void robotstop() {
  analogWrite(motorleftenb, 0);
  analogWrite(motorrightenb, 0);

}
void loop() {

  if (Serial.available()) {

    data = Serial.readStringUntil('\n');
    Serial.println(data);
    if (data == "*forward#" || data == "*1#" || data == "*Forward#") {
      analogWrite(motorleftenb, 255);
      analogWrite(motorrightenb, 255);
      x = 1;
      Serial.println("Motorforawrd");
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotbackward();
        delay(200);
        robotstop();
      }
      data = "*1#";
    }
    else if (data == "*Low forward#" || data == "*5#" || data == "*Low Forward#") {
      analogWrite(motorleftenb, 120);
      analogWrite(motorrightenb, 120);
      x = 5;
      Serial.println("Motorforawrd");
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotbackward();
        delay(200);
        robotstop();
      }
      data = "*5#";
    }
    else if (data == "*Medium forward#" || data == "*6#" || data == "*Medium Forward#") {
      analogWrite(motorleftenb, 180);
      analogWrite(motorrightenb, 180);
      x = 6;
      Serial.println("Motorforawrd");
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotbackward();
        delay(200);
        robotstop();
      }
      data = "*6#";
    }
    else if (data == "*backward#" || data == "*Backward#" || data == "*2#" || data == "*tu#" || data == "*Tu#" || data == "*tu tu#" || data == "*Tu Tu#" || data == "*TU#" || data == "*Tu tu#") {
      analogWrite(motorleftenb, 255);
      analogWrite(motorrightenb, 255);
      x = 2;
      Serial.println("Motorbackward");
      robotbackward();
      data = "*2#";
    }
    else if (data == "*left#" || data == "*3#" || data == "*Left#") {
      analogWrite(motorleftenb, 255);
      analogWrite(motorrightenb, 255);
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotstop();
        delay(200);
      }
      robotleft();
      Serial.println("Motorleft");
      delay(150);
      robotforward();
    }
    else if (data == "*right#" || data == "*4#" || data == "*Right#") {
      analogWrite(motorleftenb, 255);
      analogWrite(motorrightenb, 255);
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotstop();
        delay(200);
      }
      Serial.println("Motorright");
      robotright();
      delay(200);
      robotforward();
    }
    else if (data == "*Stop#" || data == "*0#" || data == "*stop#") {
      Serial.println("Motorstop");
      robotstop();
      delay(150);
    }
    else if (data == "*10#" || data == "*up#" || data == "*Up#") {
      for (pos = 0; pos <= 180; pos++)
        myservo.write(pos);
    }
    else if (data == "*11#" || data == "*down#" || data == "*Down#") {
      for (pos = 180; pos >= 0; pos--)
        myservo.write(pos);
    }
    else if (data == "*leftup#" || data == "*Left Up#" || data == "*Leftup#" || data == "*12#") {
      for (pos = 0; pos <= 180; pos++)
        myservo2.write(pos);
    }
    else if (data == "*leftdown#" || data == "*Left Down#" || data == "*Leftdown#" || data == "*21#") {
      for (pos = 180; pos >= 0; pos--)
        myservo3.write(pos);
    }
    else if (data == "*rigthtup#" || data == "*Rigtht Up#" || data == "*Rightup#" || data == "*13#") {
      for (pos = 0; pos <= 180; pos++)
        myservo.write(pos);
    }
    else if (data == "*rightdown#" || data == "*Right Down#" || data == "*Rightdown#" || data == "*31#") {
      for (pos = 180; pos >= 0; pos--)
        myservo.write(pos);
    }
    else {
      Serial.println("give a voice command");
    }
    robotforward();
    Serial.println("robotforward");
    Serial.println("Inside Serial");
  }
  else {
    Serial.println("Outside Serial");
    // robotforward();
    //Serial.println("forward");
    if (data == "*1#" || x == 1) {
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotstop();
        delay(300);
      }
      Serial.println("Robot  Forward");
      delay(50);
    }
    else if (data == "*6#" || x == 6) {
      analogWrite(motorleftenb, 180);
      analogWrite(motorrightenb, 180);
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotstop();
        delay(300);
      }
      Serial.println("Robot  Forward");
      delay(50);
    }
    else if (data == "*5#" || x == 5) {
      analogWrite(motorleftenb, 120);
      analogWrite(motorrightenb, 120);
      robotforward();
      distance = sending();
      Serial.println(distance);
      if (distance < 30) {
        robotstop();
        delay(300);
      }
      Serial.println("Robot  Forward");
      delay(50);
    }
    else if (data == "*2#" || x == 2) {
      robotbackward(); 
      Serial.println("Robot Backward");
      delay(50);
    }
  }

}
