// servo_coc_test.ino
//Arduino promini PWM pin number
//3,5,6,9,10,11
//Serial pin 0,1
#include <Servo.h>
int angle;//servo angle
const int servo_pin = 9;//Servo pi Arduino promini
Servo servo;//Servo instace
char read_text;
//Servo angle lenge 0 ~ 160 centor is 80 degrre

void setup() {
  servo.attach(servo_pin);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Serial.print("Start");
  angle = 80;
  servo.write(angle);//center angle
}

void right() {
  if(angle > 20){
  angle -= 20;
  servo.write(angle);
  Serial.print("right");
  Serial.println(angle);
  }
  
  }

void left() {
  if(angle < 160){
  angle += 20;
  servo.write(angle);
  Serial.print("left");
  Serial.println(angle);
  }
  
}

void centor() {
  angle = 80;
  servo.write(angle);
  Serial.print("centor");
  digitalWrite(13,HIGH);
  Serial.println(angle);
}

void loop() {

  read_text = Serial.read();
  if (read_text != -1) {
    switch (read_text)
    {
      case'a':
        right();
        break;
      case'b':
        left();
        break;
      case'c':
        centor();
        break;


    }

  } else
  {
  }

}

