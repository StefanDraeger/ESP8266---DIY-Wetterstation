double addition(double a, double b);
double subtraktion(double a, double b);
double multiplikation(double a, double b);
double division(double a, double b);

void setup() {
  Serial.begin(300);
  double a = 12;
  double b = 10;

  Serial.println(addition( a, b));
  Serial.println(subtraktion( a, b));
  Serial.println(multiplikation( a, b));
  Serial.println(division( a, b));
}

void loop() {
  //nothing
}

double addition(double a, double b) {
  return a + b;
}

double subtraktion(double a, double b) {
  return a - b;
}

double multiplikation(double a, double b) {
  return a * b;
}

double division(double a, double b) {
  return a / b;
}
