constexpr uint8_t pinNumber_x = A0;
constexpr uint8_t pinNumber_y = A1;
constexpr uint8_t pinNumber_z = A2;

constexpr float offset_x_g = 0.06015;
constexpr float offset_y_g = 0.13949;
constexpr float offset_z_g = 0.22003;


void setup() {
  Serial.begin(115200);
}


void loop() {
  float voltage_x_V = (float)analogRead(pinNumber_x) / 1024.0 * 5.0;
  float voltage_y_V = (float)analogRead(pinNumber_y) / 1024.0 * 5.0;
  float voltage_z_V = (float)analogRead(pinNumber_z) / 1024.0 * 5.0;

  float acceleration_x_g = voltage_x_V - 2.5 - offset_x_g;
  float acceleration_y_g = voltage_y_V - 2.5 - offset_y_g;
  float acceleration_z_g = voltage_z_V - 2.5 - offset_z_g;

  float angle_y_deg = atan2f(acceleration_x_g, acceleration_z_g) * (180 / PI);

  Serial.print(millis());
  Serial.print(",");
  Serial.println(angle_y_deg);

  delay(10);
}
