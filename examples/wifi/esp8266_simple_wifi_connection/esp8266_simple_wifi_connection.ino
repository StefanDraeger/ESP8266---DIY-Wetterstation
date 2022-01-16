#include <ESP8266WiFi.h>
const char* ssid = ""; //SSID aus dem Router
const char* password = ""; //Passwort für den Zugang zum WLAN
WiFiServer server(80);
void setup() {
  Serial.begin(115200); //Baudrate für die Serielle Geschwindigkeit.
  delay(10); //10ms. Warten damit die Seriele Kommunikation aufgebaut wurde.
  Serial.print("Aufbau der Verbindung zu: "); //Ausgabe der SSID auf der Seriellen Schnittstelle.
  Serial.println(ssid);
  WiFi.begin(ssid, password); //Initialisieren der Wifi Verbindung.
  while (WiFi.status() != WL_CONNECTED) { //Warten bis die Verbindung aufgebaut wurde.
    delay(500);
    //Einen Punkt auf der Seriellen Schnittstelle ausgeben so das der Benutzer erkennt dass, das Sketch noch läuft.
    Serial.print(".");
  }
  //Bei erfolgreicher Verbindung wird der folgende Text ausgeben.
  Serial.print("Mit ");
  Serial.print(ssid);
  Serial.print("erfolgreich verbunden!");
  server.begin(); // Starten des Servers.
  Serial.println("Server gestartet"); //Ausgabe auf der Seriellen Schnittstelle das der Server gestartet wurde.
  // Ausgabe der IP Adresse
  Serial.print("Adresse : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Wenn sich ein Client verbunden hat solange warten bis Daten gesendet werden.
  Serial.println("Neuer Client verbunden.");
  while (!client.available()) {
    delay(1);
  }
  client.flush();
  delay(1500);
}
