#define left_pwm  5
#define right_pwm 6
#define left_PIN_1A 7
#define left_PIN_2A 8
#define right_PIN_1A 9
#define right_PIN_2A 10
//#define trigPin 11
//#define echoPin 12

//double duration = 0;
//double distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(left_PIN_1A, OUTPUT);
  pinMode(left_PIN_2A, OUTPUT);
  pinMode(right_PIN_1A, OUTPUT);
  pinMode(right_PIN_2A, OUTPUT);
  //pinMode(echoPin, INPUT);
  //pinMode(trigPin, OUTPUT);
  
}

void loop() {
// トレース
  int pinValue1 = digitalRead(2);  //center
  int pinValue2 = digitalRead(3);  //left
  int pinValue3 = digitalRead(4);  //right

// 衝突回避
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  duration = pulseIn(echoPin, HIGH);
//
//  duration = duration / 2;
//  duration = duration / 1000000;
//  distance = duration * 340;
//  distance = distance * 100;
  
  if (pinValue1 == 1) {
    analogWrite(left_pwm, 200);
    analogWrite(right_pwm, 200);
    left_motor(HIGH, LOW);
    right_motor(HIGH, LOW);

    if (pinValue2 == 1 && pinValue3 == 1){
      left_motor(LOW, LOW);
      right_motor(LOW, LOW);
      Serial.print("1");
      delay(500);
    }

    else if (pinValue2 == 1){
      analogWrite(left_pwm, 100);
      analogWrite(right_pwm, 255);
      left_motor(HIGH, LOW);
      right_motor(HIGH, LOW);
      Serial.print("2");
    }
  
    else if (pinValue3 == 1){
      analogWrite(left_pwm, 255);
      analogWrite(right_pwm, 100);
      left_motor(HIGH, LOW);
      right_motor(HIGH, LOW);
      Serial.print("3");
    }
   }

  else if (pinValue2 == 1) {
    analogWrite(left_pwm, 100);
    analogWrite(right_pwm, 255);
    left_motor(HIGH, LOW);
    right_motor(HIGH, LOW);
    Serial.print("4");
    

   if (pinValue3 == 1) {
    left_motor(LOW, LOW);
    right_motor(LOW, LOW);
    Serial.print("5");
    delay(500);
   }    
  }

  else if (pinValue3 == 1){
    analogWrite(left_pwm, 255);
    analogWrite(right_pwm, 100);
    left_motor(HIGH, LOW);
    right_motor(HIGH, LOW);
    Serial.print("6");
  }
  
  else{
    left_motor(LOW, LOW);
    right_motor(LOW, LOW);
    Serial.print("7");
    delay(500);
  }
}

void left_motor(int la1, int la2){
  digitalWrite(left_PIN_1A, la1);
  digitalWrite(left_PIN_2A, la2);
}

void right_motor(int ra1, int ra2){
  digitalWrite(right_PIN_1A, ra1);
  digitalWrite(right_PIN_2A, ra2);
}
