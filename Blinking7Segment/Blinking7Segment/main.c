/*
 * Blinking7Segment.c
 *
 * Created: 10/24/2017 10:51:06 PM
 * Author : Rashed Bishal
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	uint8_t segment[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0xFF, 0x6F};
    DDRB |= 0x07;
	DDRC |= 0x7F;
    while (1) 
    {
		/*PORTB |= (1<<0);
		_delay_ms(250);
		PORTB &= (0<<0);
		_delay_ms(1);
		PORTB |= (2<<0);
		_delay_ms(500);
		PORTB &= (0<<1);
		_delay_ms(1);*/
		
		for(int i =0; i<10; i++)
		{
			for(int j=0; j<10; j++)	
			{
				for (int k=0; k<10; k++)
				{
					PORTB = (4<<0);
					PORTC = segment[i];
					_delay_ms(100);
					PORTB &= (0<<0);
					_delay_ms(10);
					PORTB = (2<<0);
					PORTC = segment[j];
					_delay_ms(100);
					PORTB &= (0<<0);
					_delay_ms(10);
					PORTB = (1<<0);
					PORTC = segment[k];
					_delay_ms(100);
					PORTB &= (0<<0);
					_delay_ms(10);
				}
				
			}
		}
		
    }
}

