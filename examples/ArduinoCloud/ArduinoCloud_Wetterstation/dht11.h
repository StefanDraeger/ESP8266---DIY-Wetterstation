DHTesp dht;

float getDht11TempValue() {
  return dht.getTemperature();
}

float getDht11HumidityValue() {
  return dht.getHumidity();
}
