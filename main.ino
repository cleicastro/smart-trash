#include <Servo.h>

Servo servo;
#define servoGPO D0
#define trigGPO D1
#define echoGPO D2

void setup() {
  Serial.begin(9600);
  servo.attach(servoGPO);
  servo.write(180);

  pinMode(trigGPO, OUTPUT);
  pinMode(echoGPO, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigGPO, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(trigGPO, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(trigGPO, LOW);
  duration = pulseIn(echoGPO, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("********** Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    servo.write(0);
    delay(4000);
    servo.write(180);
  }

  delay(200);
}
