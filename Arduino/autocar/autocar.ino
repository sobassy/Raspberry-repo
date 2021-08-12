#define left_pwm  5
#define right_pwm 6
#define left_PIN_1A 7
#define left_PIN_2A 8
#define right_PIN_1A 9
#define right_PIN_2A 10

int leftPower;
int rightPower;

String cmds[2];// 分割された文字列を格納する配列 

void setup() {
  Serial.begin(9600);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(left_PIN_1A, OUTPUT);
  pinMode(left_PIN_2A, OUTPUT);
  pinMode(right_PIN_1A, OUTPUT);
  pinMode(right_PIN_2A, OUTPUT);

  left_motor(HIGH, LOW);
  right_motor(HIGH, LOW);
  
}

void loop() {
//  Serial.print(leftPower);
//  Serial.print(":");
//  Serial.println(rightPower);or(HIGH, LOW);

  analogWrite(left_pwm, leftPower);
  analogWrite(right_pwm, rightPower);
  
  
//  if (pinValue1 == 1) {
//    analogWrite(left_pwm, 200);
//    analogWrite(right_pwm, 200);
//    left_motor(HIGH, LOW);
//    right_motor(HIGH, LOW);
//
//    if (pinValue2 == 1 && pinValue3 == 1){
//      left_motor(LOW, LOW);
//      right_motor(LOW, LOW);
//      Serial.print("1");
//      delay(500);
//    }
//
//    else if (pinValue2 == 1){
//      analogWrite(left_pwm, 100);
//      analogWrite(right_pwm, 255);
//      left_motor(HIGH, LOW);
//      right_motor(HIGH, LOW);
//      Serial.print("2");
//    }
//  
//    else if (pinValue3 == 1){
//      analogWrite(left_pwm, 255);
//      analogWrite(right_pwm, 100);
//      left_motor(HIGH, LOW);
//      right_motor(HIGH, LOW);
//      Serial.print("3");
//    }
//   }
//
//  else if (pinValue2 == 1) {
//    analogWrite(left_pwm, 100);
//    analogWrite(right_pwm, 255);
//    left_motor(HIGH, LOW);
//    right_motor(HIGH, LOW);
//    Serial.print("4");
//    
//
//   if (pinValue3 == 1) {
//    left_motor(LOW, LOW);
//    right_motor(LOW, LOW);
//    Serial.print("5");
//    delay(500);
//   }    
//  }
//
//  else if (pinValue3 == 1){
//    analogWrite(left_pwm, 255);
//    analogWrite(right_pwm, 100);
//    left_motor(HIGH, LOW);
//    right_motor(HIGH, LOW);
//    Serial.print("6");
//  }
//  
//  else{
//    left_motor(LOW, LOW);
//    right_motor(LOW, LOW);
//    Serial.print("7");
//    delay(500);
//  }
}

void left_motor(int la1, int la2){
  digitalWrite(left_PIN_1A, la1);
  digitalWrite(left_PIN_2A, la2);
}

void right_motor(int ra1, int ra2){
  digitalWrite(right_PIN_1A, ra1);
  digitalWrite(right_PIN_2A, ra2);
}


void serialEvent() {
  //データを1つ受信する関数（割り込み処理）です。
  String myString = Serial.readStringUntil('\n');
  int index = split(myString, ',', cmds);
  Serial.println("data gets");
     leftPower = cmds[0].toInt();
     rightPower = cmds[1].toInt();
}

int split(String data, char delimiter, String *dst){
     dst[0] = "";
     dst[1] = "";
    int index = 0;
    int arraySize = (sizeof(data)/sizeof((data)[0]));  
    int datalength = data.length();
    for (int i = 0; i < datalength; i++) {
        char tmp = data.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
