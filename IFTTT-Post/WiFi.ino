const char wifiSsid[] = "SSID";
const char wifiPass[] = "PASS";

void connectWiFi() {
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

