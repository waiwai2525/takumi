#define ANALOG_IN 0


int val;
float temp;


void setup() {
  pinMode(ANALOG_IN, OUTPUT);
}


void loop() {
  val = analogRead(ANALOG_IN);
  temp = (float)500 / 1013 * val - 50;

  Serial.print(millis());
  Serial.print(",");
  Serial.println(temp);

  delay(10);
}
