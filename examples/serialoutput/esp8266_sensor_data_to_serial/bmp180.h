Adafruit_BMP085 bmp;

void setupBmp180(){
 if (!bmp.begin())
  Serial.println("Es konnte kein BMP180 Sensor gefunden werden!");
}

float getBmp180Temperature(){
  return round(bmp.readTemperature());
}

float getBmp180Pressure(){
  return round(bmp.readPressure());
}

float getBmp180Altitude(){
  return round(bmp.readAltitude());
}
