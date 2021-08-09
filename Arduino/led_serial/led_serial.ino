void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

long led_value;

void loop() {
  if (Serial.available() > 0) {  // シリアルで受信したら
      led_value = Serial.parseInt();

      // 明るさを変える
      Serial.println(led_value);
      if (0 <= led_value < 256) {
        analogWrite(3, led_value);
      }

      while (Serial.available() > 0) {//受信バッファクリア
        char t = Serial.read();
      }
    }
}
