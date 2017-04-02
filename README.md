/*
 Developer : Towqir Ahmed Shaem
 Institute : Appplied Physics, Electronics and Communication Engineering, Chittagong University.
 Email : towqirahmedshaem@gmail.com
 */
 
 The LM35 is a common TO-92 temperature sensor. It is often used with the equation
 temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;
 The above equation comes from :
 we know when we read something from sensor in arduino we get maximum reading for any sensor which is 1024.Here 1024 means 5V.In low    temperature LM35 gives me low reading.Suppose it gives me 600.
 we know 1024 reading = 5v
 So the corresponding voltage for  600 reading = (5.0 * 600) / 1024
 Voltage = 2.93
 Milli voltage = 2930
 10mV is equal to 1 degree Celcius
 so temp = 2930 / 10
 temp = 293 celcius

 
