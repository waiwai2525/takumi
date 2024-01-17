// 定数たち
constexpr uint8_t inputPinNumber = 1;
constexpr uint8_t outputPinNumber = 9;


void setup() {
  Serial.begin(9600);
}


void loop() {
  // 入力値に応じて出力のデューティ比を変化させる処理
  // 入力値の0~1023をデューティ比の0~255に収めるために4で割る
  int16_t inputValue = analogRead(inputPinNumber);
  uint8_t dutyRatio = inputValue / 4;

  analogWrite(outputPinNumber, dutyRatio);

  Serial.print(inputValue);
  Serial.print(",");
  Serial.println(dutyRatio);

  delay(50);
}
