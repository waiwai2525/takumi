// 定数たち
constexpr uint8_t inputPinNumber = 1;
constexpr uint8_t outputPinNumber = 9;


void setup() {
  Serial.begin(9600);
}


void loop() {
  // 入力値に応じて出力のデューティ比を変化させる処理
  // 入力値は0~1023なので，0~255のデューティ比は4回オーバーフローする
  int16_t inputValue = analogRead(inputPinNumber);
  uint8_t dutyRatio = inputValue;

  analogWrite(outputPinNumber, dutyRatio);

  Serial.print(inputValue);
  Serial.print(",");
  Serial.println(dutyRatio);

  delay(100);
}
