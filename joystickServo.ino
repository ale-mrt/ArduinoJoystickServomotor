#include <Servo.h>
#define SERVO 3
#define JOY_PRESS 2
#define JOY_X 1
#define JOY_Y 0
#define INITIAL_SERVO_POS 90

Servo servo;        //this instance of Servo it's used to control the servomotor
int servo_pos = 90; //first servo position
int servoAttached = false;

void setup() {
  pinMode(JOY_PRESS, INPUT);
  digitalWrite(JOY_PRESS, HIGH);
  Serial.begin(9600);
}

void loop() {
  //if the joy is pressed then the servo activates. if it's already
  if(digitalRead(JOY_PRESS) == 0){
    if(servoAttached == false){
      servo.attach(SERVO);
      servo.write(INITIAL_SERVO_POS);
      servo_pos = INITIAL_SERVO_POS;
      servoAttached = true;
      Serial.print("SERVO ACTIVATED\n");
    }else{
      servo.detach();
      servoAttached = false;
      Serial.print("SERVO DEACTIVATED\n");
    }
    delay(1000);
  }

  if(analogRead(JOY_X) < 20){
    if(servo_pos < 180){
      servo_pos += 5;
      servo.write(servo_pos);
    }
    delay(10);
  }
  if(analogRead(JOY_X) >= 20 && analogRead(JOY_X) < 400){
    if(servo_pos < 180){
      servo_pos++;
      servo.write(servo_pos);
    }
    delay(10);
  }
  
  if(analogRead(JOY_X) > 1000){
    if(servo_pos > 0){
      servo_pos -= 5;
      servo.write(servo_pos);
    }
    delay(10);
  }
  if(analogRead(JOY_X) < 1000 && analogRead(JOY_X) > 600){
    if(servo_pos > 0){
      servo_pos--;
      servo.write(servo_pos);
    }
    delay(10);
  }
}
