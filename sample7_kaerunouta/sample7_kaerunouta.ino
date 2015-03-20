#include <math.h>
const int signal = 13;
 
void setup(){
  pinMode(signal, OUTPUT);
}
 
//noteNum: MIDIのノート番号
//length:length×0.5秒だけ音が鳴る
//ms: 周期の半分(μs)
//temp: 型変換のための一時変数
void se(double noteNum, int length){
  int ms;
  double f,temp;
   
  f = pow(2, ( (noteNum - 69)/12 )) * 440;  //MIDI Tuning Standardの式より周波数を計算
  temp = ( 1 / f * pow(10,6) / 2);
  ms = (int)temp;
   
  if(noteNum == 145){
 for(long i = 0; i < 500000 * length; i += ms*2){
  digitalWrite(signal,LOW);
        delayMicroseconds(ms);
        delayMicroseconds(ms);
    }
  }else{
    for(long i = 0; i < 500000 * length; i += ms*2){
        digitalWrite(signal,HIGH);
        delayMicroseconds(ms);
        digitalWrite(signal,LOW);
        delayMicroseconds(ms);
    }
  }
}
void loop(){
 //カエルの歌
 se(60,1);
 se(62,1);
 se(64,1);
 se(65,1);
 se(64,1);
 se(62,1);
 se(60,2);
 se(64,1);
 se(65,1);
 se(67,1);
 se(69,1);
 se(67,1);
 se(65,1);
 se(64,1);
 se(145,1);
 se(60,1);
 se(145,1);
 se(60,1);
 se(145,1);
 se(60,1);
 se(145,1);
 se(60,1);
 se(145,1);
 se(60,1);
 se(62,1);
 se(64,1);
 se(65,1);
 se(64,1);
 se(62,1);
 se(60,1);
 se(145,1);
}
