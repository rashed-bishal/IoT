/*
 * 7segment.c
 *
 * Created: 10/23/2017 9:56:33 AM
 * Author : Rashed Bishal
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int check = 0,j=1;
	DDRD |= 0x0F;
	DDRC |= 0x0F;
    while (1) 
    {
		int i=0;
		do 
		{
			if(check==0)
			{
				PORTD = (i<<0);
				_delay_ms(150);
				if(i==9) {check=1;}
				i++;
			}
			else
			{
				if(j<10)
				{
					check=0;
					PORTC = (j<<0);
					j++;
				}
				else
				{
					j=0;
					check=0;
					PORTC = (j<<0);
					j++;
				}	
			}
		} while (i<10);
    }
}
