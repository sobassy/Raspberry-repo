void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

char text[4];

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.readBytes(text, 4);
//  Serial.println(text);
  if (Serial.available() > 0) {
      long number = Serial.parseInt();
      Serial.println(number);
      while (Serial.available() > 0) {//受信バッファクリア
        char t = Serial.read();
      }
    }
}
