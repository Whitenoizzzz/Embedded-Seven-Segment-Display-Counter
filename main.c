 /**
	@file one.c
	@brief Seven segment display
*/

const char MtrNum[] __attribute__((__progmem__)) = "28850";

#define F_CPU 8000000UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/**
	@brief Init input and output
*/
void init(void){
	
	// Input
	DDRC &= ~(1 << DDC2);
	DDRC &= ~(1 << DDC3);
	PORTC |= (1 << PC2);
	PORTC |= (1 << PC3);
	
	// Output
	DDRB |= (1 << DDB0);
	DDRB |= (1 << DDB1);
	DDRB |= (1 << DDB2);
	DDRB |= (1 << DDB3);
	DDRB |= (1 << DDB4);
	DDRB |= (1 << DDB5);	
	
	DDRC |= (1 << DDC0);
	DDRC |= (1 << DDC1);

	DDRD |= (1 << DDD2);
	DDRD |= (1 << DDD3);
	DDRD |= (1 << DDD4);
	DDRD |= (1 << DDD5);
	DDRD |= (1 << DDD6);
	DDRD |= (1 << DDD7);

}
/******************************************************************************/

void sevensegment10(uint8_t value){
	static uint8_t last = 100;
	
	// stop here if no change
	if (value == last)
		return;
	
	last = value;


	// Disable all LEDs (Device: SC39)
	PORTB &= ~(1 << PB4);
	PORTB &= ~(1 << PB5);
	PORTC &= ~(1 << PC0);
	PORTC &= ~(1 << PC1);		
	PORTD &= ~(1 << PD5);		
	PORTD &= ~(1 << PD6);
	PORTD &= ~(1 << PD7);

		
	// Enable LEDs for value
	switch(value){
		
		 case(0):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
		break;
	

		case(1):
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			
		break;
		
		
		case(2):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(3):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(4):
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(5):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(6):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(7):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
		break;
		
		
		case(8):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		
		
		case(9):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
		break;
		
		
		default:
			//PORTD |= (1 << PD4); // A
			//PORTD |= (1 << PD3); // B
			//PORTD |= (1 << PD2); // C
			//PORTB |= (1 << PB0); // D
			//PORTB |= (1 << PB1); // E
			//PORTB |= (1 << PB2); // F
			PORTC |= (1 << PC1); // G
		break;
		
	
	}


}
/******************************************************************************/


void sevensegment1(uint8_t value){
	static uint8_t last = 100;
	
	// stop here if no change
	if (value == last)
		return;
	
	last = value;


	// Disable all LEDs (Device: SA39)
	PORTB &= ~(1 << PB0);
	PORTB &= ~(1 << PB1);
	PORTB &= ~(1 << PB2);
	PORTB &= ~(1 << PB3);		
	PORTD &= ~(1 << PD4);		
	PORTD &= ~(1 << PD2);
	PORTD &= ~(1 << PD3);

		
	// Enable LEDs for value
	switch(value){
	
        case(0):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
		break;
	

		case(1):
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			
		break;
		
		
		case(2):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(3):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(4):
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(5):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(6):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(7):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
		break;
		
		
		case(8):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
		
		
		case(9):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
		
		
		default:
			//PORTD |= (1 << PD4); // A
			//PORTD |= (1 << PD3); // B
			//PORTD |= (1 << PD2); // C
			//PORTB |= (1 << PB0); // D
			//PORTB |= (1 << PB1); // E
			//PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
		break;
	
	}


}
/******************************************************************************/

// This function should spilt a number from 0 to 99 into two digits.
void sevensegment(uint8_t value){
	sevensegment1(value%10);
	sevensegment10(value/10);	
}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	uint8_t value = 0;
	init(); 	// Function to initialise I/Os
	

	// Loop forever
	while (1){
		if (~PINC & (1<<PC2))
		{
			value = value == 99?99:value+1;
			_delay_ms(75);
			while (~PINC & (1<<PC2))
			{
				if (~PINC & (1<<PC3))
				{
					value=0;
					while(~PINC & (1<<PC3));
				}
			}
			_delay_ms(75);
		}
		else if (~PINC & (1<<PC3))
		{
			value = value == 0?0:value-1;
			_delay_ms(75);
			while (~PINC & (1<<PC3))
			{
				if (~PINC & (1<<PC2))
				{
					value=0;
					while(~PINC & (1<<PC2));
				}
			}
			_delay_ms(75);
		}
	   sevensegment(value);
	}
   
	return 0;
}
/******************************************************************************/

