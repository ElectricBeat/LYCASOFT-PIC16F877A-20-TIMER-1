#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 20e6
__CONFIG(0X3F3A);

int count;
	
void main()
{    
	TRISB=0X00;
	PORTB=0X00;
	TMR1H=0X00;
	TMR1L=0X00;
	T1CON=0X31;
	TMR1IF=0;

	while(1)
	{
		while(TMR1IF==0);
		TMR1IF=0;
		count++;
		if(count==5)
		{
			RB0=~RB0;
			count=0;
		}
	}
}