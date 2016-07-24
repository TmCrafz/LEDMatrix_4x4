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
	char LEDMatrixRow[4] = { PC0, PC1, PC2, PC3 };
	char LEDMatrixCol[4] = { PD0, PD1, PD2, PD3 };
	// Set PC0 - PC3 as output
	DDRC |= 0x0F;
	// Set PC0 - PC3 to low
	PORTC &= ~0x0F;
	//PORTC |= ( 1 << PC0);
	
	// Set PD0 - PD3 as output
	DDRD |= 0x0F;
	// Set PD0 - PD3 to low
	PORTD &= ~0x0F;
	
	PORTC |= ( 1 << PC2);
	PORTD |= ( (1 << PD3) | (1 << PD2) );
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

void wait(float seconds)
{
	_delay_ms(8);		
}
