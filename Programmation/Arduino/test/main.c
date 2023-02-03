#include <avr/io.h>         // header file file for input output pins
#include <util/delay.h>     // header file for delay.


int main (void) {
    /* set pin 5 of PORTB for output*/
    DDRB |= _BV(DDB5);

    while(1) {

    /* set pin 5 high to turn led on */
    PORTB |= _BV(PORTB5);
    _delay_ms(1000); //delay 1 second

    /* set pin 5 low to turn led off */
    PORTB &= ~_BV(PORTB5);
    _delay_ms(1000); //delay 1 second.
    }
}
