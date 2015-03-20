#define LED 9
const int Cds = 15;//Cdsを15番ピンに接続する
const int Cds_threshold = 500;

//最初の1回だけ実行
void setup() {
  pinMode(LED, OUTPUT); //13番pinを出力する
  pinMode(Cds, INPUT); //14番pinに入力する。
  Serial.begin(115200);//シリアルモニタとの通信速度
}

void loop() {
  int Cds_val = analogRead(Cds);//14番pinの値を読み取り
  if (Cds_val > Cds_threshold) { //もしCds_valの値をCdsthresholdが越えたら以下を実行する。
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }

  Serial.println(Cds_val);//シリアル出力する
  delay(10);

}
