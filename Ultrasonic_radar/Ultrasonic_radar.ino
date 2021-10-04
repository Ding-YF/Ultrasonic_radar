#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i=15;i<=165;i+=15){
  distance = 1000;
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(',');
  Serial.print(distance);
  Serial.println('.');
  }
}

int calculateDistance(){

    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = duration*0.034/2;
    if (distance <= 30)
        return distance;
    else 
      return -1;

}
