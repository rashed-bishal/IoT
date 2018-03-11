/*
 * Blink_zinc.c
 *
 * Created: 10/23/2017 10:12:32 AM
 * Author : user-4
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	DDRC |= 0xff;
	DDRA |= 0x7f;
	DDRB |= 0x7f;
    /* Replace with your application code */
	
char ablink[10]= {0x3f,0x06, 0x5b, 0x4f, 0x66,0x6d,0x7d,0x07,0xff, 0x6f};
char bblink[10]= {0x3f,0x06, 0x5b, 0x4f, 0x66,0x6d,0x7d,0x07,0xff, 0x6f};	
    while (1) 
    {
		
		for (int i=0; i<10; i++)
		{
			for (int j=0; j<10; j++)
			{
				PORTA = ablink[i];
				_delay_ms(1000);
			}
			for (int j=0; j<10; j++)
			{
				PORTB = bblink[j];
				_delay_ms(100);
			}
			 
		}
	

		
		/*for (int i=0; i<8; i++)
		{
			
		}
		
			
			
			/*PORTC = (170<<0);
			_delay_ms(500);
			PORTC =(0<<0);
			_delay_ms(100);
			PORTC = (85<<0);
			_delay_ms(500);
			PORTC = (0<<0);
			_delay_ms(100);
		*/
		
		
		
		/*for(int i=0; i<8; i++)
		{
			PORTC |= (1<<i);
			_delay_ms(500);
			PORTC &= (0<<i);
			_delay_ms(500);
		}
   for (int j=7; j>=0; j--)
   {
	   PORTC |= (1<<j);
	   _delay_ms(500);
	   PORTC &= (0<<j);
	   _delay_ms(500);
   }
   for (int k=0; k<8; k++)
   {
	   PORTC |= (1<<k);
	   _delay_ms(500);
   }
   for (int m=0; m<8; m++)
   {
	   PORTC &= (255<<m);
	   _delay_ms(500);
   }*/
	}
}

