void setup() {
  Serial.begin(9600);
}

void loop() {
  float aVar = .00335401;
  float bVar = .0002933908;
  float cVar = .000003494314;
  float dVar = -.000000771269;
  
  
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.print("voltage: ");
  Serial.print(voltage);
  float resistVoltage = 5.0 - voltage;
  float current = resistVoltage / 330.0;
  float resistance = voltage / current;
  Serial.print(", resistance: ");
  Serial.println(resistance);
  
  float temperature = 1/(aVar + bVar*(log(resistance/1000.0)) + cVar*(log(resistance/1000.0))*(log(resistance/1000.0)) + dVar*(log(resistance/1000.0))*(log(resistance/1000.0))*(log(resistance/1000.0)));
  
  Serial.print("Temperature in C: ");
  Serial.println( temperature - 273.0 );
  Serial.print("Temperature in F: " );
  Serial.println( ((temperature - 273.0) *1.8) + 32);
  delay( 5000 );
  
}

