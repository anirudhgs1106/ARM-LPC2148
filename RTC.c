//RTC
#include <stdio.h>
#include <lpc21xx.h>
unsigned int x,y,z,i;
char arr1[20],arr2[20],arr3[20];
void RTC(void)
{
	PREINT=0x5A;
	PREFRAC=0x46C0;
	CCR=0x00;
	SEC=0;
	MIN=24;
	HOUR=2;
	CCR=0x01;
}
void serial()
{
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x61;
	U0LCR=0x03;
}
int main()
{
	serial();
	RTC();
	while(1)
	{
		i=0;
		x=SEC;y=MIN;z=HOUR;
		sprintf(arr1,"sec:%d",x);
		while(arr1[i]!='\0')
		{
			while(!(U0LSR&0x20));
			U0THR=arr1[i];
			i++;
		}
		U0THR='\n';
		i=0;
		sprintf(arr2,"min:%d",y);
		while(arr1[i]!='\0')
		{
			while(!(U0LSR&0x20));
			U0THR=arr2[i];
			i++;
		}
		U0THR='\n';
		i=0;
		sprintf(arr3,"hour:%d",z);
		while(arr1[i]!='\0')
		{
			while(!(U0LSR&0x20));
			U0THR=arr3[i];
			i++;
		}
		U0THR='\n';
	}
}
