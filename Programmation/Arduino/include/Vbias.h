#pragma once                               // Make sure the library is only import once

#include <stdio.h>                         // Header file for standard input/output definitions
#include <math.h>                          // Header file for various mathematical functions


// ====================== Weatstone bridge equation ======================

double Vg = 0;                             // Voltage difference of the Weatstone bridge
double Rx = 0;                             // Unknown thermistor resistance
const float Vs = 3.3;                      // Weatstone bridge supply voltage
const float G = 1.494;                     // Amplifier gain
const unsigned short int Rref = 10E3;      // Weatstone bridge's resistances value


double Vbias_weatstone(double raw_ADC){
    Vg = raw_ADC / G;
    Rx = Rref*(1 - (4*Vg) / (2*Vg - Vs));
    return Rx;

}


// ====================== Steinhart-Hart equation ======================

double NLog = 0;					       // Setup the variable for the natural log of the resistance
double NLog2 = 0;                          // Setup the variable for the natural log squared of the resistance
double NLog3 = 0;                          // Setup the variable for the third power of the natural log of the resistance
double Temp = 0;					       // Setup the variable for the calculated temperature

// Steinhart-Hart temperature coefficients for the thermistor
const float A = 1.16462133E-03;
const float B = 1.68263912E-04;
const float C = 8.40212179E-06;
const float D = -1.00120322E-07;


double Vbias_steinhart(double R){
	NLog = log(R);				            // Calculate the natural log of the resistance
    NLog2 = powf(NLog, 2);                  // Calculate NLog 2nd power
    NLog3 = powf(NLog, 3);                  // Calculate NLog 3rd power
	Temp = A + B*NLog + C*NLog2 + D*NLog3;  // Run the c-Hart equation
	return powf(Temp, -1) - 273.15;         // Convert Kelvin to Celsius and return the temperature
}
