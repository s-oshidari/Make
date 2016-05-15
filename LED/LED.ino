void setup() {
  Serial.begin(115200);
  Serial.println("\nStart\n");

  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  delay(1000);
  
  digitalWrite(4, LOW);
  delay(1000);
  
}
