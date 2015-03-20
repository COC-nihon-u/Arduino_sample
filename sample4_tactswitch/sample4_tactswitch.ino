#define LED 9
const int tact  = 16;//タクトスイッチを16番pinに設定する
int switch_mode = 0;

void setup() {
  pinMode(LED, OUTPUT); //13番pinを出力する
  pinMode(tact, INPUT); //16番pinを入力にする
}

void loop(){
  if(digitalRead(tact) == HIGH){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
}


