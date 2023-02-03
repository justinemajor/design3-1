#include <stdio.h>
#include <avr/io.h>                 // header file file for input output pins

float VRef = 1.800;				    // set the value of the VREF for the ADC
float IBias = 50.00;				// set the IBias Current
float VSENSE = 0;					// set up the variable for the voltage divider
float VTEMP = 0;
int THRM_ADC;
float THRM_RES = 0;					// setup the variable for the calculated THRM resistance
float THRM_TEMP = 0;				// setup the variable for the calculated temperature
unsigned int ADC_BITS = 1048576;	// set the number of bits based on ADC (2^# of ADC Bit Value)			


float Thermistor_4th_ord_tvsr(int raw_ADC){
    // Send the ADC bit value to the calculation function				
    // THRM calculations - 4th order polynomial regression											
    VTEMP = 0;                  	// reset these variables to zero in order to recalculate the new factors				
    THRM_RES = 0;				    // reset these variables to zero in order to recalculate the new factors				
    THRM_ADC = raw_ADC;										

    float THRM_A0 =	-2.575309E+02;
    float THRM_A1 =	4.664009E-02;
    float THRM_A2 = -2.534306E-06;
    float THRM_A3 = 8.350217E-11;
    float THRM_A4 = -1.127320E-15;

    VSENSE = (VRef/ADC_BITS)*THRM_ADC;   								        // calculate volts per bit then multiply that times the ADV value
    THRM_RES =  VSENSE / (IBias/1000000);  								    // calculate the resistance of the thermistor, IBias is in uA
    THRM_TEMP = (THRM_A4*powf(THRM_RES, 4)) + (THRM_A3*powf(THRM_RES, 3));      // 4th order regression to get temperature
    THRM_TEMP = THRM_TEMP + (THRM_A2*powf(THRM_RES, 2)) + (THRM_A1*THRM_RES);
    return THRM_TEMP + THRM_A0;
}


float Thermistor_4th_ord_tvsv(int raw_ADC){											
    // Send the ADC bit value to the calculation function
    // THRM calculations - 4th order polynomial regression
    VSENSE = 0;                  	        // reset these variables to zero in order to recalculate the new factors
    THRM_ADC = raw_ADC;

    float THRM_A0 =	-2.575309E+02;
    float THRM_A1 =	9.328019E+02;
    float THRM_A2 = -1.013722E+03;
    float THRM_A3 = 6.680173E+02;
    float THRM_A4 = -1.803712E+02;

    VSENSE = (VRef/ADC_BITS)*THRM_ADC;   	                                        // calculate volts per bit then multiply that times the ADV value
    THRM_TEMP = (THRM_A4*powf(VSENSE, 4)) + (THRM_A3*powf(VSENSE, 3));				// 4th order regression to get temperature
    THRM_TEMP = THRM_TEMP + (THRM_A2*powf(VSENSE, 2)) + (THRM_A1*VSENSE);
    return THRM_TEMP + THRM_A0;
}


float IBias = 50;			    // set the IBias Current 
float bit_volt = 0.000002;		// set the voltage per bit based on the ADC bits / VREF (Set the ADC bit value in the Main tab to get the correct bit voltage)
float t_volt = 0;				// set up the variable for the divider voltage
float t_res = 0;				// setup the variable for the calculated THRM resistance
float NLog = 0;					// setup the variable for the natural log of the resistance
float Temp = 0;					// setup the variable for the calculated temperature

int steinhart(int raw_ADC){					
	float A = 0.06358635;		//temperature Coefficients for the thermistor
	float B = -0.008840611;		//temperature Coefficients for the thermistor
	float C = 0.000027084;		//temperature Coefficients for the thermistor

	t_volt = raw_ADC*bit_volt;				        // convert the raw ADC value to a measured voltage
	t_res = t_volt / (IBias/1000000);				// convert the measured voltage to a resistance, the Ibias is in uA
	NLog = log(t_res);				                // calculate the natural log of the resistance
	Temp = 1 / (A + B*NLog) + (C*NLog*NLog*NLog);	// run the c-Hart equation

	return Temp - 273.15;				            // Convert Kelvin to Celsius and return the temperature
}

