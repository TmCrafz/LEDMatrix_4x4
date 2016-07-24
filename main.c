#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

/*  Multiplexing:
 *	30x per second whole matrix (30hz)
 *  We have 4 rows: 120 row changes per Second (4 * 30)
 *  Row change after every 1/120 seconds
 */

void wait(float seconds);

int main(void)
{
	// Set register in register B pin PB1 as output
	DDRC |= (1 << PC0);
	// Set pin PB1 to high
	PORTC |= ( 1 << PC0);
	
	// Set register in register B pin PB1 as output
	DDRD |= (1 << PD0);
	// Set pin PB1 to high
	PORTD |= ( 1 << PD0);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

void wait(float seconds)
{
	_delay_ms(8);	
}
