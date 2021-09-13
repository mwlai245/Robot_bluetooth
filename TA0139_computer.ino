//Start of 
#include <Wire.h>
int MotorRight1 = 5; //IN1 PWM enabled
int MotorRight2 = 6; //IN2 PWM enabled
int MotorLeft1 = 10; //IN3 PWM enabled
int MotorLeft2 = 11; //IN4 PWM enabled
char val;

void setup()
{
  pinMode(MotorRight1, OUTPUT);  // 5 (PWM)
  pinMode(MotorRight2, OUTPUT);  // 6 (PWM)
  pinMode(MotorLeft1,  OUTPUT);  // 10 (PWM)
  pinMode(MotorLeft2,  OUTPUT);  // 11 (PWM)
  Serial.begin(9600);
}
void forward()
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
}
void backward()
{
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);;
}
void left()
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, LOW);
}
void right()
{
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, LOW);
}
void Stop()
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, LOW);
}
void loop()
{
  if(Serial.available()>0)
  {
    val=Serial.read();
    Stop();
    Serial.println(val);
    switch(val)
    {
      case 'F':
      forward();
      break;
      case 'B':
      backward();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
      case'S':
      Stop();
      break;
    }
  }
}
//End of Program
