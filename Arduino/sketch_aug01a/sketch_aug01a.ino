void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

long led_value;

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.readBytes(text, 4);
//  Serial.println(text);
  if (Serial.available() > 0) {
      led_value = Serial.parseInt();

      // 明るさを変える
      Serial.println(led_value);
      analogWrite(3, led_value);

      while (Serial.available() > 0) {//受信バッファクリア
        char t = Serial.read();
      }
    }
}
