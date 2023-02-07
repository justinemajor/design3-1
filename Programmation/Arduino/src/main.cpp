#include <Arduino.h>                // Header file for Arduino functions
#include <Vbias.h>                  // Header file for voltage bias thermistor temperature functions
// #include <Ibias.h>                  // Header file for current bias thermistor temperature functions


double in = 0;
double Vo = 0;
double V1 = 0;
double dV = 0;
double T = 0;
double R = 0;


void setup() {
  Serial.begin(115200);             // Initialize serial communication

  // Configure pins as inputs
  // pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  // Configure pins as outputs
  pinMode(2, OUTPUT);

}


void loop() {
  in = analogRead(A1);        // Read the voltage from thermistor; analogRead values go from 0 to 1023
  Vo = (5.0/1023.0)*in;

  R = Vbias_weatstone(Vo);    // Calculate thermistor resistance using nodal analysis
  T = Vbias_steinhart(R);     // Calculate thermistor temperature using Steinhart-Hart equation
  // analogWrite(2, in);               // Generate PWM with analog input
  Serial.println(T);
  delay(10);                  // Add delay in ms between each sample

}
