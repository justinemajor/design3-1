#include <Arduino.h>    // header file file for arduino functions

float logR2, R2, T;
const unsigned short R1 = 10000;
const float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(115200);       // initialize serial monitor
  pinMode(A0, INPUT);
}

void loop() {
  float Vo = analogRead(A0);  // Read the voltage from thermistor
  R2 = R1 * (1023 / Vo - 1);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)) - 273.15;

  Serial.println(T);
  delay(500);
}
