#include <lpc21xx.h>
char mg,data;
unsigned int i;
void delay()
{
	unsigned int i;
  for (i=0;i<3000;i++);
}
void serial()
{
	PINSEL0 = 0x00000005;
  U0LCR = 0x83;
  U0DLL = 0x61;
  U0LCR = 0x03;
}
char receiveUART()
{
  while (!(U0LSR & 0x01));
  mg = U0RBR;
  return mg;
}
void sendUART(unsigned char send)
{
	while (!(U0LSR & 0x20));
  U0THR = send;
}
void clk()
{
	sendUART('C');
	IOSET0=0x80000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x40000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x20000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x10000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
}
void anticlk()
{
	sendUART('A');
	IOSET0=0x10000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x20000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x40000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
	IOSET0=0x80000000;
	delay();
	IOCLR0=0xF0000000;
	delay();
}
int main()
{
	serial();
	PINSEL1 =0x00000000;
	IODIR0 =0xF0000000;
	while(1)
	{
		data=receiveUART();
		if(data=='C')
		{
			for(i=0;i<1000;i++)
			{
				clk();
			}
		}
		else if(data=='A')
		{
			for(i=0;i<1000;i++)
			{
				anticlk();
			}
		}
	}
}
