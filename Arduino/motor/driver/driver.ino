// *****************************
//   L293D motor driver
// *****************************

#define pwm    3
#define PIN_1A 5
#define PIN_2A 6

void setup() {
  pinMode(   pwm, OUTPUT);
  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_2A, OUTPUT);
}

void loop() {
  analogWrite(pwm, 150);
  motor1( HIGH,  LOW, 3000);
  motor1(  LOW,  LOW,  100);
  motor1(  LOW, HIGH, 3000);
  motor1(  LOW,  LOW,  100);
}

void motor1(int a1, int a2, int d){
  digitalWrite(PIN_1A, a1);
  digitalWrite(PIN_2A, a2);
  delay(d);
}
