/*
 * GccApplication1.c
 *
 * Created: 10/18/2017 12:41:15 PM
 * Author : Rashed Bishal
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC &= 0x00;
	DDRB |= 0xff;
	
    while (1) 
    {
		uint8_t timestamp = 0;
		timestamp = PINC & 0x01;
		
		if(timestamp == 0x01)
		{
			for(int i=0; i<8; i++)
			{
				if(i<7)
				{
					PORTB |= (1<<i);
					_delay_ms(250);
					
					PORTB &= (0<<i);
					_delay_ms(20);
				}
				else
				{
					PORTB |= (1<<i);
					_delay_ms(250);
					
					for(int j=7; j>0; j--)
					{
						PORTB &= (0<<j);
						_delay_ms(20);
						
						PORTB |= (1<<j-1);
						_delay_ms(250);
						
					}
				}
			}
		}
    }
}

