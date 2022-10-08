/*
  Mine shell Robot
   driving the four motors using PWM signals
                         --
                       |    |
               ---       ||      ---
              | C | ----------- | A |
               ---               ---
                |                 |
                |                 |
                |                 |
                |                 |
               ---               ---
              | D | ----------- | B |
               ---               ---
  A motor runs forward if its first terminal is fed a PWM signal
  and the second is fed 5v, runs reverse if vice versa, and stops
  if both were fed 5v.
*/

#define PWMValue  191

#define MotorA1 6
#define MotorA2 7
#define MotorB1 8
#define MotorB2 9
#define MotorC1 10
#define MotorC2 11
#define MotorD1 12
#define MotorD2 13

void setup()
{
 Serial.begin(19200);
 Serial3.begin(9600);
 
 pinMode(MotorA1,OUTPUT);
 pinMode(MotorA2,OUTPUT);
 pinMode(MotorB1,OUTPUT);
 pinMode(MotorB2,OUTPUT);
 pinMode(MotorC1,OUTPUT);
 pinMode(MotorC2,OUTPUT);
 pinMode(MotorD1,OUTPUT);
 pinMode(MotorD2,OUTPUT);
 
 digitalWrite(MotorA1,HIGH);
 digitalWrite(MotorA2,HIGH);
 digitalWrite(MotorB1,HIGH);
 digitalWrite(MotorB2,HIGH);
 digitalWrite(MotorC1,HIGH);
 digitalWrite(MotorC2,HIGH);
 digitalWrite(MotorD1,HIGH);
 digitalWrite(MotorD2,HIGH);
}

void loop() 
{
 if(Serial3.read() == 'f')
 {analogWrite  (MotorA1,PWMValue);
  digitalWrite (MotorA2,HIGH);
  analogWrite  (MotorB1,PWMValue);
  digitalWrite (MotorB2,HIGH);
  analogWrite  (MotorC1,PWMValue);
  digitalWrite (MotorC2,HIGH);
  analogWrite  (MotorD1,PWMValue);
  digitalWrite (MotorD2,HIGH);
  Serial.println("f");}
 else if(Serial3.read()=='b')
 {digitalWrite (MotorA1,HIGH);
  analogWrite  (MotorA2,PWMValue);
  digitalWrite (MotorB1,HIGH);
  analogWrite  (MotorB2,PWMValue);
  digitalWrite (MotorC1,HIGH);
  analogWrite  (MotorC2,PWMValue);
  digitalWrite (MotorD1,HIGH);
  analogWrite  (MotorD2,PWMValue);
  Serial.println("b");}
 else if(Serial3.read()=='l')
 {analogWrite  (MotorA1,PWMValue);
  digitalWrite (MotorA2,HIGH);
  analogWrite  (MotorB1,PWMValue);
  digitalWrite (MotorB2,HIGH);
  digitalWrite (MotorC1,HIGH);
  analogWrite  (MotorC2,PWMValue);
  digitalWrite (MotorD1,HIGH);
  analogWrite  (MotorD2,PWMValue);
  Serial.println("l");}
 else if(Serial3.read()=='r')
 {digitalWrite (MotorA1,HIGH);
  analogWrite  (MotorA2,PWMValue);
  digitalWrite (MotorB1,HIGH);
  analogWrite  (MotorB2,PWMValue);
  analogWrite  (MotorC1,PWMValue);
  digitalWrite (MotorC2,HIGH);
  analogWrite  (MotorD1,PWMValue);
  digitalWrite (MotorD2,HIGH);
  Serial.println("r");}
 else if(Serial3.read()=='n')
 {digitalWrite(MotorA1,HIGH);
  digitalWrite(MotorA2,HIGH);
  digitalWrite(MotorB1,HIGH);
  digitalWrite(MotorB2,HIGH);
  digitalWrite(MotorC1,HIGH);
  digitalWrite(MotorC2,HIGH);
  digitalWrite(MotorD1,HIGH);
  digitalWrite(MotorD2,HIGH);
  Serial.println("n");}
}
