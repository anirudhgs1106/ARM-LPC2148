//External interrupt to count the number of people entered the hall if number reaches 8 then indicate using buzzer
#include <lpc21xx.h>
#include <stdio.h>
unsigned int i=0;
void delay(unsigned int r)
{
	unsigned int j;
	for(j=0;j<r;j++);
}
void buzz()
{
	IOSET0=0x00004000;
	delay(10000);
	IOCLR0=0x00004000;
}
void extint0_isr(void)__irq
{
	i++;
	if(i>=8)
	{
		buzz();
	}
	EXTINT=0x01;
	VICVectAddr=0x00;
}
int main()
{
	PINSEL1=0x00000001;
	IODIR0=0x00004000;
	EXTMODE=0x01;
	VICVectAddr0=(unsigned long)extint0_isr;
	VICVectCntl0=0x20|14;
	VICIntEnable|=0x00004000;
	while(1);
}
