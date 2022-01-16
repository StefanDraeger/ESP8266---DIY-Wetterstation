Adafruit_BMP085 bmp;

void setupBmp180(){
 if (!bmp.begin())
  Serial.println("Es konnte kein BMP180 Sensor gefunden werden!");
}

String getBmp180Temperature(){
  String result = String(bmp.readTemperature(), 2);
  result = result + " C";
  return result;
}

String getBmp180Pressure(){
  float value = round(bmp.readPressure())/1000;
  String result = String(value, 2);
  result = result + " kPa";
  return result;
}

String getBmp180Altitude(){
  float value = round(bmp.readAltitude());
  String result = String(value, 2);
  result = result + " m";
  return result;
}
