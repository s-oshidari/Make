#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(500);
  
  Serial.println("\nStart\n");

  pinMode(5, INPUT_PULLUP);
  
  connectWiFi();
}

void loop() {
  if ( digitalRead(5) == LOW ) {
    Serial.println("button pushed!");
    postToIFTTT("IFTTTに送信するよ！");
    delay(1000);
  }
}


