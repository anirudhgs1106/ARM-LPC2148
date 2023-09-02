#include <lpc214x.h>
#include <stdio.h>
#define desired_count	1000  // 1 sec Delay
#define prescalar	245  //(246Khz * 0.001)-1
void InitTimer0(void)
{
	T0PR=prescalar;
	T0MR0=desired_count;
	T0MCR=3;
	T0TCR=2;
}
int main()
{
	int value;
	PINSEL1=0x00080000;
	while(1)
	{
		value=1023;
		DACR=((1<<16) | (value<<6));
		InitTimer0();
		value=0;
		DACR=((1<<16) | (value<<6));
		InitTimer0();
	}
}
