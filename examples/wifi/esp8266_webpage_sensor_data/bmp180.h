Adafruit_BMP085 bmp;

void setupBmp180(){
 if (!bmp.begin())
  Serial.println("Es konnte kein BMP180 Sensor gefunden werden!");
}

String getBmp180Temperature(){
  return String(bmp.readTemperature(), 2);
}

String getBmp180Pressure(){
  float value = round(bmp.readPressure());
  return String(value, 2);
}

String getBmp180Altitude(){
  float value = round(bmp.readAltitude());
  return String(value, 2);
}
