constexpr uint8_t inputPinNumber = 1;
constexpr uint8_t outputPinNumber = 9;


void setup() {
  Serial.begin(115200);
}


void loop() {
  int16_t inputValue = analogRead(inputPinNumber);
  uint8_t dutyRatio = inputValue / 4;

  analogWrite(outputPinNumber, dutyRatio);

  Serial.print(inputValue);
  Serial.print(",");
  Serial.println(dutyRatio);

  delay(50);
}
