//Monitor blood pressure using analog sensor and indicate using buzzer if reaches threshold value
#include <lpc214x.h>
#include <stdio.h>
unsigned int adc_val=0,temp_adc=0,i,j;
char val[30];
void delay(unsigned int k)
{
	for(j=0;j<k;j++);
}
void initial()
{
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x61;
	U0LCR=0x03;
}
void buzz()
{
	IOSET0=0x00004000;
	delay(10000);
	IOCLR0=0x00004000;
}
int main()
{
	PINSEL1=0x00040000;
	IODIR0=0x00004000;
	initial();
	while(1)
	{
		AD0CR=0x09200010;
		delay(100);
		while((temp_adc=AD0GDR)==0x80000000);
		adc_val=AD0GDR;
		adc_val>>=6;
		adc_val&=0x000003FF;
		if(adc_val > 512)
		{
			buzz();
		}
		sprintf(val,"Digital value is %x",adc_val);
		while(val[i]!='\0')
		{
			while(!(U0LSR&0x20));
			U0THR=val[i];
			i++;
		}
		delay(2000);
		U0THR='\n';
		i=0;
	}
}
