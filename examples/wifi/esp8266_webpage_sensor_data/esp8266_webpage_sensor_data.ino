#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include "DHTesp.h"
#include <Adafruit_BMP085.h>

#include "uvsensor.h"
#include "dht11.h"
#include "bmp180.h"

const char* ssid = "FRITZBox7590GI_EXT";
const char* password = "22894580214767401850";

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
  Serial.print(" erfolgreich verbunden!");
  server.begin(); // Starten des Servers.
  Serial.println("Server gestartet"); //Ausgabe auf der Seriellen Schnittstelle das der Server gestartet wurde.
  // Ausgabe der IP Adresse
  Serial.print("Adresse : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  // DHT11 Sensor am D6, GPIO12
  dht.setup(12, DHTesp::DHT11);

  // PIN des UV Sensors als Eingang definieren
  pinMode(uvSensorIn, INPUT);

  setupBmp180();
}



/**
   Die Funktion gibt den HTML Kopf auf dem Client aus.
   Dieses wird für jeden Respond verwendet.
 **/
void writeResponse(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
  client.println("<style>");
  client.println("table, th, td {border: 1px solid black; margin: 0px auto; width: auto;}");
  client.println("h1 {text-align:center;}");
  client.println("#outer {margin:0px auto; width: 550px;}");
  client.println("</style>");
  
  client.println("<body>");
  client.println("<div id='outer'>");
  client.println("<h1>DIY Weatherstation V2</h1>");
  client.println("<h1>Sensordaten</h1>");
  client.println("<table>");
  client.println("<thead>");
  client.println("<tr><th>Sensor</th><th>Wert</th></tr>");
  client.println("</thead>");
  client.println("<tbody>");

  delay(dht.getMinimumSamplingPeriod());
  client.println("<tr><td><b>DHT11</b></td><td></td></tr>");
  client.println("<tr><td>Temperatur</td><td>" + getDht11TempValue() + " &#8451;</td></tr>");
  client.println("<tr><td>rel. Luftfeuchtigkeit</td><td>" + getDht11HumidityValue() + " %</td></tr>");

  client.println("<tr><td><b>BMP180</b></td><td></td></tr>");
  client.println("<tr><td>Temperatur</td><td>" + getBmp180Temperature() + " &#8451;</td></tr>");
  client.println("<tr><td>Luftdruck</td><td>" + getBmp180Pressure() + " Pa</td></tr>");

  client.println("<tr><td><b>UV-Sensor</b></td><td></td></tr>");
  client.println("<tr><td></td><td>" + getUvSensorValue() + " mW/cm&sup2;</td></tr>");

  client.println("</body>");
  client.println("</table>");
  client.println("</div>");
  client.println("</body>");
  client.println("</html>");
}

void loop() {
  //Prüfen ob sich ein Client verbunden hat, wenn nicht die Loop "verlassen"
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wenn sich ein Client verbunden hat solange warten bis Daten gesendet werden.
  Serial.println("Neuer Client verbunden.");
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  writeResponse(client);

  delay(1); //1ms. Pause
}
