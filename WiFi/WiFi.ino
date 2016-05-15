#include <ESP8266WiFi.h>

const char wifiSsid[] = "";
const char wifiPass[] = "";

void setup() {
  Serial.begin(115200);
  Serial.println("\nStart\n");

  Serial.print("WiFi Connecting...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSsid, wifiPass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("OK!");
  Serial.println("--");

  WiFi.printDiag(Serial);
  Serial.println("--");
  Serial.println("WiFi ready!");
}

void loop() {
}
