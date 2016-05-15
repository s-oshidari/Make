const char iftttEvent[] = "D-Make-Post";
const char iftttKey[]   = "TOKEN";
const int  iftttPort    = 80;
const char iftttHost[]  = "maker.ifttt.com";

void postToIFTTT(String param1) {
  
  String url = "/trigger/" + (String)iftttEvent + "/with/key/" + (String)iftttKey;
  String data = "{\"value1\":\"" + param1 + "\"}";
  
  WiFiClient client;

  Serial.println("\n[IFTTT] Connecting...");
  if (!client.connect(iftttHost, iftttPort)) {
    Serial.println("[IFTTT] Connection failed");
    
  } else {
    client.println("POST " + url + " HTTP/1.1");
    client.print(F("Host: "));
    client.println(iftttHost);
    client.println(F("User-Agent: ESP8266/1.0"));
    client.println(F("Connection: close"));
    client.println(F("Content-Type: application/json; charset=utf-8"));
    client.print(F("Content-Length: "));
    client.println(data.length());
    client.println();
    client.println(data);
    delay(10);
    String response = client.readString();
    int bodypos = response.indexOf("\r\n\r\n") + 4;
    Serial.println("--");
    Serial.println(response.substring(bodypos));
  }
}

