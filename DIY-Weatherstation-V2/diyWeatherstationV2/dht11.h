DHTesp dht;

String getDht11TempValue() {
  delay(dht.getMinimumSamplingPeriod());
  float temperatur = dht.getTemperature();
  return String(temperatur, 2) + "C";
}

String getDht11HumidityValue() {
  delay(dht.getMinimumSamplingPeriod());
  float luftfeuchtigkeit = dht.getHumidity();
  return String(luftfeuchtigkeit, 2) + "%";
}
