#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  for (int i=15;i<=165;i++){
  myServo.write(i);
  delay(30);  //延迟30毫秒
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(',');
  Serial.print(distance);
  Serial.println('.');
  }

  for (int i=165;i<=15;i--){
  myServo.write(i);
  delay(30);  //延迟30毫秒
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(',');
  Serial.print(distance);
  Serial.println('.');
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
    if (distance <= 30)
        return distance;
    else 
        return -1;

}
