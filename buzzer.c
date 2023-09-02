#include <lpc21xx.h>
void delay(int c)
{
	unsigned int i;
	for(i=0;i<c;i++);
	for(i=0;i<c;i++);
}
int main()
{
	PINSEL0=0x00000000;
	IODIR0=0x00004000;
	while(1)
	{
		IOCLR0=0x00004000;
		delay(10000);
		delay(10000);
		IOSET0=0x00004000;
		delay(10000);
		delay(10000);
	}
}
