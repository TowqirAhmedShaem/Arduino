float Kp = 10, Ki = 0.0001, Kd = 1;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[6] = {0, 0, 0, 0, 0, 0};
bool sensorRead[3]={false, false, false};
int initial_motor_speed = 200;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

void setup()
{
  pinMode(9, OUTPUT); //PWM Pin 1
  pinMode(10, OUTPUT); //PWM Pin 2
  pinMode(7, OUTPUT); //Left Motor Pin 1
  pinMode(8, OUTPUT); //Left Motor Pin 2
  pinMode(2, OUTPUT); //Right Motor Pin 1
  pinMode(3, OUTPUT); //Right Motor Pin 2
  Serial.begin(9600); //Enable Serial Communications
}

void loop()
{
  read_sensor_values();
  calculate_pid();
  motor_control();
}

void read_sensor_values()
{
  sensor[0]= analogRead(A0);
  if(sensor[0]>500 /*when sensor closer to ground400*/) sensor[0]=1;
  else sensor[0]=0;
  sensor[1] = analogRead(A1);
  if(sensor[1]>500 /*when sensor closer to ground400*/) sensor[1]=1;
  else sensor[1]=0;
  sensor[2] = analogRead(A2); 
  if(sensor[2]>500 /*when sensor closer to ground400*/) sensor[2]=1;
  else sensor[2]=0;
  sensor[3]= analogRead(A3);
  if(sensor[3]>500 /*when sensor closer to ground400*/) sensor[3]=1;
  else sensor[3]=0;
  sensor[4] = analogRead(A4);
  if(sensor[4]>500 /*when sensor closer to ground400*/) sensor[4]=1;
  else sensor[4]=0;
  sensor[5] = analogRead(A5); 
  if(sensor[5]>500 /*when sensor closer to ground400*/) sensor[5]=1;
  else sensor[5]=0;

  Serial.print("Sensors ");
  Serial.print(sensor[0]);
  Serial.print(" ");
  Serial.print(sensor[1]);
  Serial.print(" ");
  Serial.print(sensor[2]);
  Serial.print(" ");
  Serial.print(sensor[3]);
  Serial.print(" ");
  Serial.print(sensor[4]);
  Serial.print(" ");
  Serial.println(sensor[5]);
//  Serial.println(sensor[0]);
//  Serial.println(sensor[1]);
//  Serial.println(sensor[2]);
//  Serial.println("set end");
//  delay(500);
  delay(10);
  /*
    sensor[3] = digitalRead(A3);
    sensor[4] = digitalRead(A4);
  */

  /*
    if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==1))
    error=4;
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==1)&&(sensor[4]==1))
    error=3;
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==1)&&(sensor[4]==0))
    error=2;
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[4]==1)&&(sensor[4]==0))
    error=1;
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[4]==0)&&(sensor[4]==0))
    error=0;
    else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[4]==0)&&(sensor[4]==0))
    error=-1;
    else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
    error=-2;
    else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
    error=-3;
    else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
    error=-4;
    else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
    if(error==-4) error=-5;
    else error=5;
  */
  /*if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1))
    error = 2;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1))
    error = 1;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0))
    error = 0;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0))
    error = -1;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0))
    error = -2;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0))
    if (error == -2) error = -3;
   else error = 3;*/
   if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0))//111110
    error=5;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0))//111100
    error=4;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0))//111000
    error=3;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))//110001
    error=1;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))//111001
    error=2;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==1))//111101
    error=3;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))//111011
//    error=1;
    error=0;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))//110011
    error=0;
   else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1))//100011
    error=-1;
   else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//100111
    error=-2;
   else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//101111
    error=-3;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//110111
//    error=-1;
    error=0;
   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//000111
    error=-3;
   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//001111
    error=-4;
   else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))//011111
    error=-5;
    /*
   else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))
    error=-2;
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))
    error=-3;
   else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1))
    error=-4;
    */
   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1))
   {
    if((error>=-5&&error<=0)) error=-6;    else if(error<=5&&error>=0) error=6;
   }
}

void calculate_pid()
{
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  Serial.print("P ");Serial.println(P);
 Serial.print("I ");Serial.println(I);
 Serial.print("D ");Serial.println(D);
  PID_value = (Kp * P) + (Ki * I) + (Kd * D);
  Serial.print("PID ");Serial.println(PID_value);
  previous_I = I;
  previous_error = error;
}

void motor_control()
{
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed + /*3**/PID_value;//- then + is WRONG appearantly
  int right_motor_speed = initial_motor_speed - /*3**/PID_value;


  // The motor speed should not exceed the max PWM value
  constrain(left_motor_speed, 0, 255);
  constrain(right_motor_speed, 0, 255);
  Serial.print("Motor Speed LeftRight ");
  if(left_motor_speed>255) left_motor_speed=255;
  if(right_motor_speed>255) right_motor_speed=255;
  Serial.print(left_motor_speed);
  Serial.print(" ");
  Serial.println(right_motor_speed);
  
  analogWrite(10, left_motor_speed); //Left Motor Speed
  analogWrite(9, right_motor_speed); //Right Motor Speed
  //following lines of code are to make the bot move forward
  /*The pin numbers and high, low values might be different
    depending on your connections */
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}
