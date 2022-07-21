#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "FRITZBox7590GI_EXT";
const char* password = "22894580214767401850";

ESP8266WebServer server(80);

void handleRoot() {
  float temperatur = 0.4;
  float luftfeuchtigkeit = 54;
  float luftdruck = 956;
  float uvIntensitaet = 3.5;
  
  String webseite = "<html><body><h1>DIY - Wetterstation v2</h1><p>Temperatur: "+String(temperatur, 2)+" &deg;C</p><p>rel. Luftfeuchtigkeit "+String(luftfeuchtigkeit, 2)+" &#x25;</p><p>Luftdruck "+String(luftdruck, 2)+" hPa</p><p>UV-Intensit&auml;t "+String(uvIntensitaet, 2)+" mW/cm&sup2;</p></body></html>";
  server.send(200, "text/html", webseite);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
 Serial.begin(115200); //Baudrate für die Serielle Geschwindigkeit.
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  Serial.println("");
  Serial.print("Aufbau der Verbindung zu: "); //Ausgabe der SSID auf der Seriellen Schnittstelle.
  Serial.println(ssid);
  Serial.println("");
  WiFi.begin(ssid, password); //Initialisieren der Wifi Verbindung.
  while (WiFi.status() != WL_CONNECTED) { //Warten bis die Verbindung aufgebaut wurde.
    delay(500);
    //Einen Punkt auf der Seriellen Schnittstelle ausgeben so das der Benutzer erkennt dass, das Sketch noch läuft.
    Serial.print(".");
  }
  Serial.println("");
  //Bei erfolgreicher Verbindung wird der folgende Text ausgeben.
  Serial.println("Mit " + String(ssid) + " erfolgreich verbunden!");
  server.begin(); // Starten des Servers.
  
  // Ausgabe der IP Adresse
  Serial.print("Adresse : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
