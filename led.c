#include <lpc21xx.h>
void delay(int c)
{
	int i;
	for(i=0;i<c;i++);
}
int main()
{
	PINSEL1=0x00000000;
	IODIR0=0x000F0000;
	while(1)
	{
		IOCLR0=0x00010000;
		delay(100000);
		IOSET0=0x000F0000;
		delay(100000);
		
		IOCLR0=0x00020000;
		delay(100000);
		IOSET0=0x000F0000;
		delay(100000);
		
		IOCLR0=0x00040000;
		delay(100000);
		IOSET0=0x000F0000;
		delay(100000);
		
		IOCLR0=0x00080000;
		delay(100000);
		IOSET0=0x000F0000;
		delay(100000);
	}
}
