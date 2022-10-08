#define TrigPin 8
#define EchoPin 9
#define Range   20 
#define NumberOfReadings 5

void setup() 
{
  Serial.begin (4800);
  Ultrasonic_Initialize();
}

void loop() 
{
  //if(Serial.read() == 'R')
  {
    Read_Ultrasonic_Range();
  }
}

void Ultrasonic_Initialize()
{
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void Read_Ultrasonic_Range()
{
  long duration, distance, sum = 0;
  float avg_distance = 0;
  for(int i = 0; i < NumberOfReadings; i++)
  {
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(5); // Added this line
    digitalWrite(TrigPin, LOW);
    duration = pulseIn(EchoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("Distance Measured: ");
    Serial.print(distance);
    Serial.println(" cm");
    sum += distance;
    delay(25);
  }
  avg_distance = sum/NumberOfReadings;
  Serial.print("Average Distance: ");
  Serial.print(avg_distance);
  Serial.println(" cm");
  Serial.println("------------------------------");
  sum = 0;
  avg_distance = 0;
  if(distance < Range)
    Serial.println("Obstacle Found");
  else
    Serial.println("No Obstacle");
  Serial.println("---------------------------");
}

