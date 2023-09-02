#include <lpc21xx.h>
void delay()
{
	int i;
	for(i=0;i<100000;i++);
}
int main()
{
	int j;
	int arr[16]={0x003F0000,0x00060000,0x005B0000,0x004F0000,0x00660000,0x006D0000,0x007D0000,0x00070000,0x007F0000,0x006F0000,0x00770000,0x007C0000,0x00390000,0x005E0000,0x00790000,0x00710000};
	PINSEL1=0x00000000;
	while(1)
	{
		for(j=0;j<15;j++)
		{
			IODIR0=0xF0FF0000;
			IOSET0=0x10000000;
			IOSET0=arr[j];
			delay();
			IOCLR0=arr[j];
			delay();
		}
	}
}
