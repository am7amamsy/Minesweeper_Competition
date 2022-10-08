/*Mine shell Remote control 
controlling in three types of mtion regular & rotational about
the center of the robot and backward one side only
pin configration: 
                 ----------------------------
                 |     F            F1      |
                 |  L     R      F4    F2   |
                 |     B            F3      |
                 ----------------------------
                 
UART wirless module connected to software UART 
hardware can be connected on serial monitor or to UART wirless
module (remove the module while uploading a code)

*/
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#define Forward  A0
#define Right  A1
#define Backward A2 
#define Left  A3

#define F1  7
#define F2  4
#define F3  5
#define F4  6

int F,B,R,L,f1,f2,f3,f4;

void setup()
{
 //Serial setup 
 Serial.begin(19200);
 mySerial.begin(9600);
 //pin setup
 pinMode(Forward,INPUT);
 pinMode(Backward,INPUT);
 pinMode(Right,INPUT);
 pinMode(Left,INPUT);
 pinMode(F1,INPUT);
 //pinMode(F2,INPUT);
 pinMode(F3,INPUT);
 //pinMode(F4,INPUT);
 }
 void loop()
{
 F=digitalRead(Forward);
 B=digitalRead(Backward);
 R=digitalRead(Right);
 L=digitalRead(Left);
 f1=digitalRead(F1);
 //f2=digitalRead(F2);
 f3=digitalRead(F3);
 //f4=digitalRead(F4);
 
 //controlling in regular motion
 if(F==HIGH&&B==LOW&&R==LOW&&L==LOW&&f1==LOW&&f3==LOW)
 {
  mySerial.write('f');//forward
  Serial.write('f');
  delay(20);
  }
  
 else if(F==LOW&&B==HIGH&&R==LOW&&L==LOW&&f1==LOW&&f3==LOW)
 {
  mySerial.write('b');//backward
  Serial.write('b');
  delay(20);
  }
  
 else if(F==LOW&&B==LOW&&R==HIGH&&L==LOW&&f1==LOW&&f3==LOW)
 {
  mySerial.write('r');//right
  Serial.write('r');
  delay(20);
  }
  
 else if(F==LOW&&B==LOW&&R==LOW&&L==HIGH&&f1==LOW&&f3==LOW)
 {
  mySerial.write('l');//left
  Serial.write('l');
  delay(20);
  }
  //end regular motion
  
 //Function 1 controlling clock wise and anti clock wise rotation
  else if(F==LOW&&B==LOW&&R==LOW&&L==HIGH&&f1==HIGH&&f3==LOW)
 {
  mySerial.write('c');//clock wise rotation
  Serial.write('c');
  delay(20);
  }
  
  else if(F==LOW&&B==LOW&&R==HIGH&&L==LOW&&f1==HIGH&&f3==LOW)
 {
  mySerial.write('a');//anti clock rotation
  Serial.write('a');
  delay(20);
  }
  //end Function 1 control 
  
   //Function 3 controlling backward one side
  else if(F==LOW&&B==LOW&&R==LOW&&L==HIGH&&f1==LOW&&f3==HIGH)
 {
  mySerial.write('k');//left backward
  Serial.write('k');
  delay(20);
  }
  
  else if(F==LOW&&B==LOW&&R==HIGH&&L==LOW&&f1==LOW&&f3==HIGH)
 {
  mySerial.write('e');//right backward
  Serial.write('e');
  delay(20);
  }
  //end Function 3 control
 
 //noting pressed send n
 else
 {
  mySerial.write('n');//nothing
  Serial.write('n');
  delay(20);
  }
}//end loop

