#include <Servo.h>

#define buttonRight 9
#define buttonLeft 8
Servo servoMotor;
double potenValor;
double valorMotor;
byte buttonRightState;
byte buttonLeftState;
int servoMotorValue = 180;

void setup() {  
  pinMode(buttonRight, INPUT_PULLUP);
  pinMode(buttonLeft, INPUT_PULLUP);
  servoMotor.attach(3);
  servoMotor.write(180);
  Serial.begin(9600);
  

}

void loop() {
  servoMotor.write(servoMotorValue);
  Serial.println(servoMotorValue);
  buttonRightState = digitalRead(buttonRight);
  buttonLeftState = digitalRead(buttonLeft);
  if(buttonRightState == LOW) {
    //Serial.println("Direito!");
    if(servoMotorValue <= 180) {
      servoMotorValue += 2;
    }
  }else if (buttonLeftState == LOW) {
    //Serial.println("Esquerdo!");
    if(servoMotorValue >= 0) {
      servoMotorValue -= 2;
    }
  }
}
