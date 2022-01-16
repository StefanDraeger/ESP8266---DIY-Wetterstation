// UV Sensor am analogen PIN A0
int uvSensorIn = A0;

const float inMin = 0.99;
const float inMax = 2.9;
const float outMin = 0.0;
const float outMax = 15.0;

const byte numberOfReadings = 8;

//Ließt den PIN x mal und berechnet aus der Anzahl der gelesenen Werte den
//Durchschnittswert und liefert diesen zurück.
int averageAnalogRead(int pinToRead) {
  unsigned int runningValue = 0;
  for (int x = 0 ; x < numberOfReadings ; x++) {
    runningValue += analogRead(pinToRead);
  }
  return (runningValue / numberOfReadings);
}

//Arduino map Funktion unterstützt kein Float daher wurde diese neu implementiert
//(eine Kopie aus dem Arduino Forum)
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

String getUvSensorValue() {
  int uvLevel = averageAnalogRead(uvSensorIn);
  float outputVoltage = 3.3 * uvLevel / 1024;
  float uvIntensity = mapfloat(outputVoltage, inMin, inMax, outMin, outMax);
  return String(uvIntensity, 2);
}
