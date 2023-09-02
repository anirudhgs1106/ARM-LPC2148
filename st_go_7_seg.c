//Display st indicating stop signal for 5 secs and go indicating Go signal for 2 secs on 7 segment for traffic light controlling
#include <stdio.h>
#include <lpc21xx.h>
void initimer0()
{
	T0PR=11999;
	T0MR0=2000;
	T0TCR=2;
	T0MCR=3;
}
void initimer1()
{
	T1PR=11999;
	T1MR0=5000;
	T1TCR=2;
	T1MCR=3;
}
void display_st()
{
	IOSET0=0x206D0000;
	IOSET0=0x10060000;
}
void display_go()
{
	IOSET0=0x207D0000;
	IOSET0=0x103F0000;
}
int main()
{
	PINSEL1=0x00000000;
	IODIR0=0x30FF0000;
	initimer0();
	initimer1();
	while(1)
	{
		T0TCR=0x01;
		display_go();
		while(!(T0IR==0x01));
		T0IR=0x01;
		IOCLR0=0x30FF0000;
		T0TCR=0x02;
	
		T1TCR=0x01;
		display_st();
		while(!(T1IR==0x01));
		T1IR=0x01;
		IOCLR0=0x30FF0000;
		T1TCR=0x02;
	}
}
