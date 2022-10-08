#include <SPI.h>
#include <SD.h>

File myFile;
int sensor = 0;
int distance = 8;

void setup()
{Serial.begin(9600);
 //Serial.print("Initializing SD card...");
 if (!SD.begin(4)) 
 {//Serial.println("initialization failed!");
    return;}
  //Serial.println("initialization done.");
 pinMode(7,INPUT);
}

void loop()
{ String dataString = "";
  sensor = digitalRead(7);
  if((sensor == HIGH)&&(distance <= 10))
  {dataString += "Surface Mine Detected";
   Serial.println(dataString);
   sensor = digitalRead(7);
   delay(250);}
  else if((sensor == HIGH)&&(distance > 10))
  {dataString += "Buried Mine Detected";
   Serial.println(dataString);
   sensor = digitalRead(7);
   delay(250);}
  else if(sensor == LOW)
  {dataString += "No Mines";
   Serial.println(dataString);
   delay(250);
   sensor = digitalRead(7);}
  myFile = SD.open("data.txt", FILE_WRITE);
  if (myFile) {
    //Serial.print("Writing to test.txt...");
    myFile.println(dataString);
    myFile.close();}
}

