#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

/*  Multiplexing:
 *	30x per second whole matrix (30hz)
 *  We have 4 rows: 120 row changes per Second (4 * 30)
 *  Row change after every 1/120 seconds
 */

void wait();

int main(void)
{
	// We use the Ports PC0 - PC3 and PD0 - PD3 as outputs for the LED Matrix
	const char LEDMatrixRow[4] = { 1 << PC0,  1 << PC1, 1 << PC2,  1 << PC3 };
	const char LEDMatrixCol[4] = { 1 << PD0, 1 << PD1, 1 << PD2, 1 << PD3 };
			
	// Set PC0 - PC3 as output
	DDRC |= 0x0F;
	// Set PD0 - PD3 as output
	DDRD |= 0x0F;
	
	//PORTC = LEDMatrixRow[3];
	//PORTD = LEDMatrixCol[3] | LEDMatrixCol[2] | LEDMatrixCol[1] | LEDMatrixCol[0];
	
	
    while (1) 
    {
		// We have to multiplex the LED Matrix, so only the LEDs of one row are lighting at the same time		
		for (char i = 0; i != 4; i++) 
		{
			// Get the row which is on
			char row = LEDMatrixRow[i];
			char columns = 0;
			// Now get all LEDs of this column
			for (char j = 0; j != 4; j++)
			{
				columns |= LEDMatrixCol[j];				
			}
			// Let the LEDs glow
			PORTC = row;
			PORTD = columns;
			// Wait until we let the next row glow
			wait();
		}		
    }	
} 

void wait()
{
	_delay_ms(80);		
}
