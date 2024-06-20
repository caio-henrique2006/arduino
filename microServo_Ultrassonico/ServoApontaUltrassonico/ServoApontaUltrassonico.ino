#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonicRight(8, 9);
Ultrasonic ultrasonicLeft(10, 11);
Servo servoMotor;
double valueRight;
double valueLeft;

void setup() {  
  servoMotor.attach(3);
  servoMotor.write(90);
  Serial.begin(9600);
}

void loop() {
  Serial.println(valueRight);
  Serial.println(valueLeft);
  valueRight = ultrasonicRight.read(CM);
  valueLeft = ultrasonicLeft.read(CM);
  Serial.println(valueLeft);
  if(valueRight >= valueLeft) {
    servoMotor.write(30);
  } else if (valueLeft >= valueRight) {
    servoMotor.write(150);
  }

}
