//int led = 11;
//int number;
//void setup()
//{
//  Serial.begin(9600);
//  
//  pinMode(led,OUTPUT);
// digitalWrite(led,LOW);
//}
//void loop()
//{
// if(Serial.available())
// {
//   String value = Serial.readStringUntil('\n');
//   //Serial.println(value);
//   if(value == "on")
//   {
//     analogWrite(led,255);
//   }
//   else if(value == "off")
//   {
//     analogWrite(led,LOW);
//   }
//   else if(value=="bling"){
//    analogWrite(led,255);
//    delay(300);
//    analogWrite(led,100);
//    delay(300);
//    analogWrite(led,0);
//    delay(400);
//   }
//  
// }
//}



//code for control arduino by voice from your phone:


int led = 11;
void setup()
{
  Serial.begin(9600);
  
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}
void loop()
{
 if(Serial.available())
 {
   String value = Serial.readStringUntil('\n');
   Serial.println(value);
   if(value == "*1#")
   {
     digitalWrite(led,HIGH);
   }
   else if(value == "*0#") 
   {
     digitalWrite(led,LOW);
   }
   else if(value=="*bling#"){
    analogWrite(led,255);
    delay(300);
    analogWrite(led,100);
    delay(300);
    analogWrite(led,0);
    delay(400);
   }
    else if(value == "*100#") 
   {
     analogWrite(led,100);
   }
  
 }
}
