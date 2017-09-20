
#include <Servo.h>. 

const int trigPin = 3;
const int echoPin = 2;

long duration;
int distance;
Servo myServo;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  myServo.attach(9); 
}
void loop() {
  
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }

  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  if (distance < 40)
    {
      digitalWrite(4,HIGH);
        digitalWrite(11,HIGH);
      
    }
    else
    {
      digitalWrite(4,LOW);
        digitalWrite(11,LOW);
    }
     return distance;
  
 
}
