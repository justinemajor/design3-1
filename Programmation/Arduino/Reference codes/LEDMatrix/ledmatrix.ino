//http://www.youtube.com/user/greatscottlab 

#include "Tlc5940.h"  //don't forget to download the Tlc5940 lib from arduino playground ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#define RowOne 8      //Gate of 1.MOSFET which connects to Row "a" (anodes of all LEDs in Row "a")
#define RowTwo 7      //Gate of 2.MOSFET which connects to Row "b" (anodes of all LEDS in Row "b")
#define RowThree 6    //Gate of 3.MOSFET which connects to Row "c" (anodes of all LEDs in Row "c")
#define RowFour 5     //Gate of 4.MOSFET which connects to Row "d" (anodes of all LEDs in Row "d")
#define RowFive 4     //Gate of 5.MOSFET which connects to Row "e" (anodes of all LEDs in Row "e")

                   
int RowDuration = 4000;     // ON time of each Row in microseconds  
int row = 0;                // starting with Row 0 (Row "a")
unsigned long oldMicros = 0;// starting counter to decide when if(micros()>=oldMicros)is true to change active row, count++1, MatrixUpdate(); don't know what micros() is? Look here: http://arduino.cc/de/Reference/Micros#.UygzAIWmWd4
int count=0;                // starting counter which is included in if() statement to change the shown picture, not necessary when using a static picture
int stretch=20;             // set timer for the change of the shown picture, if animation should move really fast then low stretch value, if animation should move really slow than big stretch value
int bright=1000;            // set brightness for all LEDs(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a LED you have to change the value in tab "function"


void setup()
{
  pinMode(RowOne, OUTPUT);  // declare arduino nano pin 8(RowOne) as OUTPUT
  pinMode(RowTwo, OUTPUT);  // declare arduino nano pin 7(RowTwo) as OUTPUT
  pinMode(RowThree, OUTPUT);// declare arduino nano pin 6(RowThree) as OUTPUT
  pinMode(RowFour, OUTPUT); // declare arduino nano pin 5(RowFour) as OUTPUT
  pinMode(RowFive, OUTPUT); // declare arduino nano pin 4(RowFive) as OUTPUT
  Tlc.init();               // configures the arduino to use the tlc5940, be sure to connect the arduino correctly to the tlc 
 
 /*          ARDUINO                                         TLC5940                            
              13|-> SCLK (pin 25)           OUT1 Column "B" |1     28| OUT0 Column "A"
              12|                           OUT2 Column "C" |2     27|-> GND (VPRG)
              11|-> SIN (pin 26)            OUT3 Column "D" |3     26|-> SIN (pin 11)
              10|-> BLANK (pin 23)          OUT4 Column "E" |4     25|-> SCLK (pin 13)
               9|-> XLAT (pin 24)           OUT5 Column "F" |5     24|-> XLAT (pin 9)
               8|                           OUT6 Column "G" |6     23|-> BLANK (pin 10)
               7|                           OUT7 Column "H" |7     22|-> GND
               6|                           OUT8 Column "I" |8     21|-> VCC (+5V)
               5|                           OUT9 Column "J" |9     20|-> 2K Resistor -> GND
               4|                           OUT10           |10    19|-> +5V (DCPRG)
               3|-> GSCLK (pin 18)          OUT11           |11    18|-> GSCLK (pin 3)
               2|                           OUT12           |12    17|-> SOUT (only used when you want to use more than one tlc5940)
               1|                           OUT13           |13    16|-> XERR (can be used as error report, but not necessary)
               0|                           OUT14           |14    15| OUT15        */
  }

void loop(){
  
  if(micros()>= oldMicros){                                         // waits until RowDuration is reached and than goes through cycle
    oldMicros=micros()+RowDuration;                                 // updates oldMicros value by adding the micros() with RowDuration
   if(count==0){reset();sin1();}//Eletter1();}//pos1();}            // shows first static picture when count==0, so right at the beginng
   if(count==stretch){reset();sin2();}//Eletter2();}//pos2();}      // shows second static picture when count==2*stretch
   if(count==2*stretch){reset();sin3();}//Eletter3();}//pos3();}    // .
   if(count==3*stretch){reset();sin4();}//Eletter4();}//pos4();}    // .
   if(count==4*stretch){reset();sin5();}//Eletter5();}//pos5();}    // .
   if(count==5*stretch){reset();sin6();}//Eletter6();}//pos6();}    // .
   if(count==6*stretch){reset();sin7();}//Eletter7();}//pos7();}    // .
   if(count==7*stretch){reset();sin8();}//Eletter8();}//pos8();}    // .
   //if(count==8*stretch){reset()//Eletter9();}//pos9();}  // .
   //if(count==9*stretch){reset();Eletter10();}//pos10();}          // shows 10. static picture when count ==9*stretch
   MatrixUpdate(row);                                               // sets the values for the tlc5940 Outputs and puts all MOSFET Gates HIGH (not active) except for one MOSFET Low (active) -->this row is ON, also look under tab "function"  
   row++;                                                           // row counter +1, so MatrixUpdate(row) will affect the next row during the next if() cycle 
   count++;                                                         // count counter +1, to change the picture in next if() cycle
   if(row==6){row = 1;}                                             // we only have 5 rows, so we start with row 1 again if row counter goes to 6
   if (count==8*stretch){count=0;}                                  // we have 8 static picture for the moving sine wave, so if count counter would hit the 9.(not existing) pic, it goes back to count=0
   }}
