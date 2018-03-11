/*
 * GccApplication2.c
 *
 * Created: 10/22/2017 12:22:17 PM
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
			for(int h=0; h<9; h++)
			{
				PORTB |=~ (255<<h);
				_delay_ms(300);
			}
				for(int i=0; i<8; i++)
				{
					if(i<7)
					{
						PORTB |= (255<<i);
						_delay_ms(300);
						PORTB &= (0<<0);
					}
					else
					{
						PORTB |= (255<<i);
						_delay_ms(300);
						PORTB &= (0<<0);
						_delay_ms(300);
						
						for(int j=7; j>=0; j--)
						{
							
							PORTB |= (255<<j);
							_delay_ms(300);
							PORTB &= (0<<0);
						}
						for(int k=1; k<8; k++)
						{
							if(k<7)
							{
								PORTB |= (255>>k);
								_delay_ms(300);
								PORTB &= (0>>0);
							}
							else
							{
								PORTB |= (255>>k);
								_delay_ms(300);
								PORTB &= (0>>0);
							}
						}
					}				
			}
		}
	}
}

