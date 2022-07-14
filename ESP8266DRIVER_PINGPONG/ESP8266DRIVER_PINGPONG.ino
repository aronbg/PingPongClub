#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
     
const char* ssid = "Aars";
const char* password = "aroniscool";

ESP8266WebServer server(80);
MDNSResponder mdns;
     
String webPage = "";
     
int led_pin = 51;
     
void setup(void){
     
  // подготовка:
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  

  webPage += "<h1>ESP8266 Web Server</h1>";
  webPage += "</p>";
  webPage += "<p>LED state <a href=\"LedON\"><button>ON</button></a>&nbsp;<a href=\"LedOFF\"><button>OFF</button></a></p>";

  WiFi.begin(ssid, password);
  Serial.println("");
     

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");  //  "Подключились к "
  Serial.println(ssid);
  Serial.print("IP address: ");  //  "IP-адрес: "
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
     
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  
  server.on("/LedON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, HIGH);
    Serial.println("[ON]");
    delay(1000);
  });
  
  server.on("/LedOFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });

    server.on("/Led?????", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });
  
  server.begin();
  Serial.println("HTTP server started");
  
}
     
void loop(void){
  server.handleClient();
}
