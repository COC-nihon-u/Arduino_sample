#include <Stepper.h>

#define STEPS 300                       // ステッピングモータの１回転あたりのステップ数

Stepper Motor(STEPS, 8, 9, 10, 11) ;    // stepperクラスのインスタンスを生成する

void setup()
{
     Motor.setSpeed(100) ;               // モータの速さを毎分の回転数(RPM)で設定する
}
void loop()
{
     Motor.step(100) ;                    // ４ステップのみ回転させる
}
