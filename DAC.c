#include <lpc214x.h>
#include <stdio.h>
unsigned int val,i;
void delay(unsigned int r1)
{
	unsigned int r;
	for(r=0;r<r1;r++);
}
unsigned int sin_wave[42] = {512,591,665,742,808,873,926,968,998,1017,1023,1017,998,968,926,873,808,742,665,
								591,512,436,359,282,216,211,151,97,55,25,6,0,6,25,55,97,151,211,216,282,359,436};
int main()
{
	PINSEL1=0x00080000;
	while(1)
	{
		//Square Wave
		val=1023;
		DACR=((1<<16)|(val<<6));
		delay(1000);
		val=0;
		DACR=((1<<16)|(val<<6));
		delay(1000);
		
		//Triangular Wave
		for(i=0;i<1023;i++)
		{
			val=i;
			DACR=((1<<16)|(val<<6));
		}
		for(i=1023;i>0;i--)
		{
			val=i;
			DACR=((1<<16)|(val<<6));
		}
		
		//Sinusoidal Wave
		for(i=0;i<42;i++)
		{
			val=sin_wave[i];
			DACR=((1<<16)|(val<<6));
			delay(1);
		}
	}
}
