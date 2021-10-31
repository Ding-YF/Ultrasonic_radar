#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
int LED = 9;

Servo myServo;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  myServo.attach(12);
  myServo.write(15);
  pinMode(LED,OUTPUT);
}

void loop() {
  for (int i=5;i<=175;i++){
  myServo.write(i);
  delay(30);  //延迟30毫秒
  distance = calculateDistance();
  if (distance<=5)
  {
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
  Serial.print(123);
  Serial.print(".");
  Serial.print(i);
  Serial.print(".");
  Serial.print(distance);
  Serial.println(".");
  }

  for (int i=175;i>=5;i--){
  myServo.write(i);
  delay(30);  //延迟30毫秒
  distance = calculateDistance();
  if (distance<=5)
  {
    Serial.print(666666);
  }
//   else{
//     digitalWrite(LED,LOW);
//   }
  Serial.print(321);
  Serial.print(".");
  Serial.print(i);
  Serial.print(".");
  Serial.print(distance);
  Serial.println(".");
  }

}

int calculateDistance(){

    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);  //延迟2微秒
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);  //延迟10微秒
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);  //计算echoPin脚高电平的时间
    distance = duration*0.034/2;
    if (distance <= 45)
        return distance;
    else 
        return 500;

}
