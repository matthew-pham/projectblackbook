
#include "WiFi.h"
#include "WebServer.h"

const char *ssid = "ESP32";
const char *password = "test123";

WebServer server(80);

void setup() {
  Serial.println("hi");
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  server.on("/", handle_OnConnect);
 
  server.begin();
  Serial.println("HTTP server started");
  }
  void handle_OnConnect() {
  Serial.println("Hi");
  server.send(200, "text/html", "<h1>Hello Brandon, this is running on an ESP32 server</h1>"); 
}


void loop() {
server.handleClient();
}
