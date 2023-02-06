#pragma once

#include <stdio.h>
#include <avr/io.h>                     // Header file for input output pins
#include <math.h>                       // Header file for various mathematical functions


// ====================== 4th order polynomial equation ======================

const float VRef = 1.8;				    // Set the value of the VREF for the ADC
const unsigned int IBias = 50;		    // Set the IBias Current
float VSENSE = 0;					    // Set up the variable for the voltage divider
float VTEMP = 0;                        // Set up the variable for the measured voltage
int THRM_ADC;
float THRM_RES = 0;					    // Setup the variable for the calculated THRM resistance
float THRM_TEMP = 0;				    // Setup the variable for the calculated temperature
float ADC_BITS = 1048576;	// Set the number of bits based on ADC (2^# of ADC Bit Value)


float Ibias_4th_ord_tvsr(float raw_ADC){
    // Send the ADC bit value to the calculation function

    // THRM calculations - 4th order polynomial regression
    VTEMP = 0;                  	    // Reset these variables to zero in order to recalculate the new factors
    THRM_RES = 0;				        // Reset these variables to zero in order to recalculate the new factors
    THRM_ADC = raw_ADC;

    const float THRM_A0 = -2.575309E+02;
    const float THRM_A1 = 4.664009E-02;
    const float THRM_A2 = -2.534306E-06;
    const float THRM_A3 = 8.350217E-11;
    const float THRM_A4 = -1.127320E-15;

    VSENSE = (VRef/ADC_BITS)*THRM_ADC;   								        // Calculate volts per bit then multiply that times the ADV value
    THRM_RES =  VSENSE / (IBias/1000000);  								        // Calculate the resistance of the thermistor, IBias is in uA
    THRM_TEMP = (THRM_A4*powf(THRM_RES, 4)) + (THRM_A3*powf(THRM_RES, 3));      // 4th order regression to get temperature
    THRM_TEMP = THRM_TEMP + (THRM_A2*powf(THRM_RES, 2)) + (THRM_A1*THRM_RES);
    return THRM_TEMP + THRM_A0;
}


float Ibias_4th_ord_tvsv(float raw_ADC){
    // Send the ADC bit value to the calculation function
    // THRM calculations - 4th order polynomial regression
    VSENSE = 0;                  	        // Reset these variables to zero in order to recalculate the new factors
    THRM_ADC = raw_ADC;

    float THRM_A0 =	-2.575309E+02;
    float THRM_A1 =	9.328019E+02;
    float THRM_A2 = -1.013722E+03;
    float THRM_A3 = 6.680173E+02;
    float THRM_A4 = -1.803712E+02;

    VSENSE = (VRef/ADC_BITS)*THRM_ADC;   	                                        // Calculate volts per bit then multiply that times the ADV value
    THRM_TEMP = (THRM_A4*powf(VSENSE, 4)) + (THRM_A3*powf(VSENSE, 3));				// 4th order regression to get temperature
    THRM_TEMP = THRM_TEMP + (THRM_A2*powf(VSENSE, 2)) + (THRM_A1*VSENSE);
    return THRM_TEMP + THRM_A0;
}


// ====================== Steinhart-Hart equation ======================


float t_volt = 0;				// Set up the variable for the divider voltage
float t_res = 0;				// Setup the variable for the calculated THRM resistance
float NLog = 0;					// Setup the variable for the natural log of the resistance
float Temp = 0;					// Setup the variable for the calculated temperature
const float bit_volt = 0.000002;		// Set the voltage per bit based on the ADC bits / VREF (Set the ADC bit value in the Main tab to get the correct bit voltage)


float Ibias_steinhart(float raw_ADC){
	float A = 0.06358635;		// Temperature Coefficients for the thermistor
	float B = -0.008840611;		// Temperature Coefficients for the thermistor
	float C = 0.000027084;		// Temperature Coefficients for the thermistor

	t_volt = raw_ADC*bit_volt;				        // Convert the raw ADC value to a measured voltage
	t_res = t_volt / (IBias/1000000);				// Convert the measured voltage to a resistance, the Ibias is in uA
	NLog = log(t_res);				                // Calculate the natural log of the resistance
	Temp = 1 / (A + B*NLog) + (C*NLog*NLog*NLog);	// Run the c-Hart equation

	return Temp - 273.15;				            // Convert Kelvin to Celsius and return the temperature
}
