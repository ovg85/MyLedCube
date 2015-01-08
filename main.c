#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


void init(void);

int main (void)
{
	init();
}

void init(void)
{
	TCNT2 = 0x00;	// initial counter value = 0;
	TIMSK |= (1 << OCIE2); // Enable CTC interrupt
	OCR2 = 15; 			// interrupt at counter = 15
	TCCR2 = 0x05; 		// prescaler = 1024
	TCCR2 |= (1 << WGM21);	// Clear Timer on Compare Match (CTC) mode
}

// Cube buffer draw interrupt routine
ISR(TIMER2_COMP_vect)
{
	
}