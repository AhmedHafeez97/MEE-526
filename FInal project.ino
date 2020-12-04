char t='S'; //variable declaration for characters to receive 
#define sensor A0 //Left sensor declaration
#define sensor1 A1 //Front sensor declaration
int en1=3; //declaration of enable pin for motor driver
int en2=5; //declaration of enable pin for motor driver
int m1=6;  //declaration of motor pin for motor driver
int m2=7;  //declaration of motor pin for motor driver
int m3=8;  //declaration of motor pin for motor driver 
int m4=9;  //declaration of motor pin for motor driver
 
void setup() {
pinMode(6,OUTPUT);   //declaring motor pins as output
pinMode(7,OUTPUT);   //declaring motor pins as output
pinMode(8,OUTPUT);   //declaring motor pins as output
pinMode(9,OUTPUT);   //declaring motor pins as output
pinMode(3,OUTPUT);   //declaring enable pins as output
pinMode(5,OUTPUT);   //declaring enable pins as output
analogWrite(3,125);  //declaring analog voltage on enable pin for better mechanical stabilization
analogWrite(5,150);  //declaring analog voltage on enable pin for better mechanical stabilization
Serial.begin(9600);  //start the serial port
}
 
void loop() {
if(Serial.available())//Reading serial communication for any character available
{
  t = Serial.read();//storing character in t
  Serial.println(t);//print the character on serial window
}
 
if(t == 'F'){          //if F is received move forward(all motors rotate in forward direction)
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}
 
else if(t == 'B'){      //if B is received move reverse (all motors rotate in reverse direction)
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
 
else if(t == 'L'){      //if L is received turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}
 
else if(t == 'R'){      //if R is received turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){//STOP (all motors stop)
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}
else if (t=='G') //if G is received switch the bot to autonomous mode
{
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  float volts1 = analogRead(sensor1)*0.0048828125;  // value from sensor * (5/1024)
  int distance1 = 13*pow(volts1, -1); // worked out from datasheet graph
  delay(150); // slow down serial port 
  Serial.print("front= ");//displaying front sensor value on serial monitor
  Serial.println(distance1);//displaying front sensor value on serial monitor 
  Serial.print("side= ");//displaying side sensor value on serial monitor
  Serial.println(distance);//displaying side sensor value on serial monitor
    if ((distance>=3)&&(distance<=10))//defining loop for forward direction using left sensor value
     {
       //declaring loop for forward movement
       analogWrite(3,125);
       analogWrite(5,150);
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       Serial.println("forward"); //viewing executing loop on serial monitor
     }
    else if ((distance>=5)&&(distance<=9))//defining loop for left direction using left sensor value
     { //declaring loop for left movement
       analogWrite(3,125);
       analogWrite(5,150);
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       delay(100);
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(100);
       Serial.println("left");//viewing executing loop on serial monitor
      }
    else if ((distance>=3)&&(distance<=6)&&(distance1>=10))//defining loop for right direction using sensors for corners
     {  //declaring loop for right movement
       analogWrite(3,125);
       analogWrite(5,150);
       digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(100);
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(100);
       Serial.println("right");//viewing executing loop on serial monitor
      }
     else if ((distance>16))//defining loop for turning on left edge
      {
       analogWrite(3,125);
       analogWrite(5,125);
       digitalWrite(m1,HIGH);
       digitalWrite(m2,LOW);
       digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       delay(120);
       digitalWrite(m1,HIGH);//forward command is to align the bot parallel to the wall again
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(100);}
     else if ((distance>=3)&&(distance<=10)&&(distance<=12))//defining loop for turning on left edge
      {
       analogWrite(3,125);
       analogWrite(5,125);
       digitalWrite(m1,LOW);
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(70);
       digitalWrite(m1,LOW); 
       digitalWrite(m2,LOW);
       digitalWrite(m3,LOW);
       digitalWrite(m4,LOW);
       delay(120); 
       digitalWrite(m1,HIGH);//forward commands is to align the bot back to the wall
       digitalWrite(m2,LOW);
       digitalWrite(m3,HIGH);
       digitalWrite(m4,LOW);
       delay(120);
      }
      }
       delay(10);
      }
