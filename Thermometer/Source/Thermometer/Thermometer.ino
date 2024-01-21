constexpr uint8_t temperaturePinNumber = 0;


void setup() {
  Serial.begin(115200);
}


void loop() {
  float voltage_V = (float)analogRead(temperaturePinNumber) / 1024.0 * 5.0;
  float temperature_degC = 100.0 * voltage_V - 50;

  Serial.print(millis());
  Serial.print(",");
  Serial.println(temperature_degC);

  delay(10);
}
