constexpr uint8_t pinNumber_x = 0;
constexpr uint8_t pinNumber_y = 1;
constexpr uint8_t pinNumber_z = 2;

constexpr float offset_x_g = 0.0601540436456838;
constexpr float offset_y_g = 0.139492900608509;
constexpr float offset_z_g = 0.220039920159696;


void setup() {
  Serial.begin(9600);
}


void loop() {
  // 電圧を取得
  float voltage_x_V = (float)analogRead(pinNumber_x) / 1023.0 * 5.0;
  float voltage_y_V = (float)analogRead(pinNumber_y) / 1023.0 * 5.0;
  float voltage_z_V = (float)analogRead(pinNumber_z) / 1023.0 * 5.0;

  // 電圧を加速度に換算
  float acceleration_x_g = voltage_x_V - 2.5 - offset_x_g;
  float acceleration_y_g = voltage_y_V - 2.5 - offset_y_g;
  float acceleration_z_g = voltage_z_V - 2.5 - offset_z_g;

  // 角度を算出
  float angle_y_deg = atan2f(acceleration_x_g, acceleration_z_g) * (180 / PI);

  // CSVで出力
  Serial.print(millis());
  Serial.print(",");
  Serial.println(angle_y_deg);

  delay(10);
}
