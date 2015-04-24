#define LED_PIN 13
 long counter = 0;
boolean led = false;


// 初期化
void setup(){
  pinMode(LED_PIN, OUTPUT);
 
  // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(9600);
}


//=======================================================================

  void mode1(){
    Serial.print("LED ON\n");
    digitalWrite(LED_PIN, HIGH);
  }
  
  void mode2(){
    Serial.print("LED OFF\n");
    digitalWrite(LED_PIN, LOW);
  }
    
  void mode3(){//押すたびにON/OFF
    Serial.print("LED FLASHING\n");
       while(1){
       digitalWrite(LED_PIN, HIGH);   // set the LED on
       delay(100);       // wait for a second
       digitalWrite(LED_PIN, LOW);    // set the LED off
       delay(100); 
       }
       
     }

    


//=======================================================================

void loop(){
  int inputchar;
  
 
  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
 
  if(inputchar != -1 ){
    // 読み込んだデータが -1 以外の場合　以下の処理を行う
 
    switch(inputchar){
      case 'o':
        // 読み込みデータが　o の場合
        mode1();
        break;
      case 'p':  
        // 読み込みデータが　p の場合
        mode2();
        break;
        
       case'q':
        mode3();              
        break;
    }
  } else {
    // 読み込むデータが無い場合は何もしない
  }
}


