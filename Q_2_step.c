#include <lpc214x.h>
#include <stdio.h>
#define desired_count	1000  // 1 sec Delay
#define prescalar	245  //(246Khz * 0.001)-1
int arr[11]={0,100,200,300,400,500,600,700,800,900,1000};
void InitTimer0(void)
{
	T0PR=prescalar;
	T0MR0=desired_count;
	T0MCR=3;
	T0TCR=2;
}
int main()
{
	int value,i;
	PINSEL1=0x00080000;
	while(1)
	{
		for(i=0;i<12;i++)
		{
			value=arr[i];
			DACR=((1<<16) | (value<<6));
			InitTimer0();
		}
	}
}
