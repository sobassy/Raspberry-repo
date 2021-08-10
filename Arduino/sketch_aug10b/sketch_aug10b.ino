//********************************************************************
//* フォトリフレクタからの入力でLEDを光らせるプログラム
//********************************************************************
int pin = A0; //
int pinLED = 13;
void setup() {
Serial.begin(9600) ;
pinMode(pinLED,OUTPUT);
}
void loop() {
int val;
val = analogRead(pin) ; //アナログ1番ピンからセンサ値を読み込み
Serial.println(val) ; // シリアルモニターへ表示
}
