#include <Arduino.h>                // Header file for Arduino functions
#include <SPI.h>                    // Header file for SPI devices communication functions
#include <Vbias.h>                  // Header file for voltage bias thermistor temperature functions

double Vo = 0;
double V1 = 0;
double T = 0;
double R = 0;
unsigned short int in = 0;

// Settings for Arduino UNO
const unsigned short int CS = 10;
// static const unsigned short int MISO = 12;
SPISettings UNO(16e6, MSBFIRST, SPI_MODE0);

// Settings for ATSAMD21
const unsigned short int CS1 = 1;
const unsigned short int CS2 = 2;
const unsigned short int CS3 = 3;
const unsigned short int CS4 = 4;
const unsigned short int CS5 = 5;
const unsigned short int CS6 = 6;
const unsigned short int CS7 = 7;
const unsigned short int CS8 = 8;
const unsigned short int S0 = 11;
const unsigned short int S1 = 12;
const unsigned short int S2 = 13;
// const unsigned short int MISO = 10;
SPISettings ATSAMD21(48e6, MSBFIRST, SPI_MODE0);


void setup() {
  // Serial.begin(11520);          // Initialize Serial Communication
  SPI.begin();                  // Initialize SPI Communication

  pinMode(CS, OUTPUT);          // Set Chip-Select pin to Output
  pinMode(MISO, INPUT);         // Configure MISO pin as Input

  // Enable internal pullups for unused pins 
  // pinMode(A0, INPUT_PULLUP);
  // pinMode(A2, INPUT_PULLUP);

}


void loop() {
  SPI.beginTransaction(UNO);        // Read the selected ADC's output byte
  digitalWrite(CS, LOW);            // Pull the CS pin Low to activate ADC's output

  in = SPI.transfer(0);             // Read ADC output
  Vo = 5/4096 * in;                 // Convert input bytes to voltage

  R = Vbias_wheatstone(Vo);         // Compute thermistor resistance using nodal analysis
  T = Vbias_steinhart(R);           // Compute thermistor temperature using Steinhart-Hart equation
  Serial.println(R, 6);             // Display thermistor temperature to serial monitor
  digitalWrite(CS, HIGH);           // Pull the CS pin High to deactivate ADC's output
  SPI.endTransaction();             // End ADC communication
  // delay(5);                         // Add 5 ms delay between acquisition

}
