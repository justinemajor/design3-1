#include <Arduino.h>
#include <HardwareSerial.h>
#include <math.h>

double A = 0.001130407327;
double B = 0.0002339285378;
double C = 0.00000008837346307;

//

int16_t adc = ads.readADC_SingleEnded(0); // read from A0

Serial.print("Raw adc: ");
Serial.println(adc);

float volts = ads.computeVolts(adc); // calculate voltage

Serial.print("Volts: ");
Serial.println(volts, 3);

float val = 3.3 / volts - 1;
float resistance = SERIESRESISTOR / val;

Serial.print("Thermistor resistance "); 
Serial.println(resistance);

double steinhart = 1 / (A + B * log(resistance) + C * pow(log(resistance), 3)) - 273.15;                    

Serial.print("Temperature "); 
Serial.print(steinhart);
Serial.println(" *C");
