//Up count on 7 segnment and indicate odd number on buzzer
#include <lpc21xx.h>
#include <stdio.h>
unsigned int i=0;
void delay(unsigned long int r)
{
	unsigned long int j;
	for(j=0;j<r;j++);
	for(j=0;j<r;j++);
	for(j=0;j<r;j++);
	for(j=0;j<r;j++);
}
void buzz()
{
	IOSET0=0x00004000;
	delay(10000);
	IOCLR0=0x00004000;
}
void display()
{
	unsigned int arr[10]={0x003F0000,0x00060000,0x005B0000,0x004F0000,0x00660000,0x006D0000,0x007D0000,0x00070000,0x007F0000,0x006F0000};
	int m,n;
	m=i%10;
	n=i/10;
	IOSET0=0x20000000;
	IOSET0=arr[m];
	IOSET0=0x10000000;
	IOSET0=arr[n];
	//IOSET0=0x10000000;
	//IOSET0=arr[i];
	delay(100000);
	IOCLR0=0x30FF0000;
}
int main()
{
	IODIR0=0x30FF4000;
	while(1)
	{
		display();
		if((i/2)!=0)
		{
			buzz();
		}
		i++;

	}
}
