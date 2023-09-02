#include <lpc21xx.h>
void delay(int c)
{
	unsigned int i;
	for(int i=0;i<c;i++);
	for(int i=0;i<c;i++);
}
void clk()
{
	IOSET0=0x00000800;
	IOCLR0=0x00000400;
}
void anticlk()
{
	IOSET0=0x00000400;
	IOCLR0=0x00000800;
}
int main()
{
	PINSEL0=0x00000000;
	IODIR0=0x00000C00;
	while(1)
	{
		clk();
		delay(20000);
		//delay(10000);
		anticlk();
		delay(20000);
		//delay(10000);
	}
}