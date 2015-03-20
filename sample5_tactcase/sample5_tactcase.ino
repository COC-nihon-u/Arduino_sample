

#define LED_red 3
#define LED_blue 5
#define LED_green 6
const int tact1  = 14;
const int tact2  = 15;
const int tact3  = 16;

int red = 255;
int blue = 255;
int green = 255;
int switch_mode = 0;

void setup() {
  pinMode(tact1, INPUT);
  pinMode(tact2, INPUT);
  pinMode(tact3, INPUT);
  Serial.begin(115200);
  Serial.print("start_switch mode");
}

void loop() {
  //条件分岐を行う。
   if (digitalRead(tact1) == HIGH) {
    switch_mode = 1;
  } else if (digitalRead(tact2) == HIGH) {
    switch_mode = 2;
  } else if (digitalRead(tact3) == HIGH) {
    switch_mode = 3;
  }
 
  switch (switch_mode)//switch_modeで場合分けを行う
  {
    case 1:
      analogWrite(LED_red, red);
      analogWrite(LED_blue, 0);
      analogWrite(LED_green, 0);
      break;

    case 2:
      analogWrite(LED_red, 0);
      analogWrite(LED_blue, blue);
      analogWrite(LED_green, 0);
      break;

    case 3:
      analogWrite(LED_red, 0);
      analogWrite(LED_blue, 0);
      analogWrite(LED_green, green);
      break;
  }

  Serial.println(switch_mode);
  delay(10);


}

