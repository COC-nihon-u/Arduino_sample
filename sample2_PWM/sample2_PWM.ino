//Arduino Unoの場合
//PWM出力できるpinは決まっている。
//3, 5, 6, 9, 10, 11　このピンしかできない

#define LED 9
const int volume = 14;//可変抵抗の値の読み取りに使用

//最初の1回だけ実行
void setup() {
  pinMode(LED, OUTPUT); //13番pinを出力する
  pinMode(volume, INPUT); //14番pinに入力する
  Serial.begin(115200);//シリアルモニタとの通信速度
}

void loop() {
  int val = analogRead(volume);//14番pinの電圧を読みとる
  val = val / 3;//読み取った値は大きいので3で割る
  analogWrite(LED, val); //13番pinにPWM出力する。
  Serial.println(val);//シリアルモニタに可変抵抗の値を表示


}
