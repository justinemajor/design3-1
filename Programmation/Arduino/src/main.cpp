#include <Arduino.h>                // Header file for Arduino functions
#include <SPI.h>                    // Header file for SPI devices communication functions
#include <Vbias.h>                  // Header file for voltage bias thermistor temperature functions
// #include <Ibias.h>                  // Header file for current bias thermistor temperature functions


double Vo = 0;
double V1 = 0;
double T = 0;
double R = 0;
unsigned short int in = 0;


void setup() {
  Serial.begin(115200);             // Initialize serial communication

  // Configure pins as inputs
  pinMode(A1, INPUT);

  // Configure pins as outputs
  pinMode(2, OUTPUT);

  // Enable internal pullups for unused pins 
  pinMode(A0, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP),

}


void loop() {
  in = analogRead(A1);        // Read the voltage from thermistor; analogRead values go from 0 to 1023
  Vo = (5.0/1024.0)*in;

  R = Vbias_weatstone(Vo);    // Calculate thermistor resistance using nodal analysis
  T = Vbias_steinhart(R);     // Calculate thermistor temperature using Steinhart-Hart equation
  // analogWrite(2, in);         // Generate PWM with analog input
  Serial.println(T, 6);
  delay(10);                  // Add delay in ms between each sample

}
