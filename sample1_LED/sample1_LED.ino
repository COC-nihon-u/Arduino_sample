#define LED 13 //使うピンを定義

//最初の1回だけ実行
void setup() {
  pinMode(LED, OUTPUT); //13番pinを出力する
}

//ここでループを行う。
void loop() {
  digitalWrite(LED, HIGH); //13番pinに5vが流れる
  delay(500);//500ms,0.5秒止まる

  digitalWrite(LED, LOW); //13番pinに出力しない
  delay(500);//500ms,0.5秒止まる

}
