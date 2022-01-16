DHTesp dht;

String getDht11TempValue() {
  float temperatur = dht.getTemperature();
  return String(temperatur, 2);
}

String getDht11HumidityValue() {
  float luftfeuchtigkeit = dht.getHumidity();
  return String(luftfeuchtigkeit, 2);
}
