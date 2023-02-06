#pragma once

#include <stdio.h>                      // Header file for standard input/output definitions
#include <math.h>                       // Header file for various mathematical functions


// ====================== Weatstone bridge equation ======================


// const int R = 10E3;     // Weatstone bridge's resistances value
double Vg = 0;
double Rx = 0;
const float Vs = 3.3;   // Weatstone bridge supply voltage
const float G = 1.494;
const int Rref = 10E3;


double Vbias_weatstone(double raw_ADC){
    Vg = raw_ADC / G;
    Rx = Rref*(1 - (4*Vg) / (2*Vg - Vs));
    return Rx;

}

// ====================== Steinhart-Hart equation ======================


double NLog = 0;					                    // Setup the variable for the natural log of the resistance
double NLog2 = 0;
double NLog3 = 0;
double Temp = 0;					                    // Setup the variable for the calculated temperature

// Steinhart-Hart temperature coefficients for the thermistor
double A = 1.16462133E-03;
double B = 1.68263912E-04;
double C = 8.40212179E-06;
double D = -1.00120322E-07;


double Vbias_steinhart(double R){
	NLog = log(R);				        // Calculate the natural log of the resistance
    NLog2 = powf(NLog, 2);                    // Calculate NLog 2nd power
    NLog3 = powf(NLog, 3);                    // Calculate NLog 3rd power
	Temp = A + B*NLog + C*NLog2 + D*NLog3;	// Run the c-Hart equation
	return powf(Temp, -1) - 273.15;				            // Convert Kelvin to Celsius and return the temperature
}
