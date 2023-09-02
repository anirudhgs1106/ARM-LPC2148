#include <lpc21xx.h>
#define desired_count	3000
#define prescalar	11999
/*void delay()
{
	unsigned int i;
	for(i=0;i<10000;i++);
}*/
void InitTimer0(void)
{
	T0PR=prescalar;
	T0MR0=desired_count;
	T0MCR=3;
	T0TCR=2;
}
void serial()
{
	PINSEL0|= 0x00050000;
  U1LCR = 0x83;
  U1DLL = 0x61; //0x31;
	U1LCR = 0x03;
	U1FDR = 0x10;
}
void sendUART(char send)
{
	while (!(U1LSR & 0x20));
  U1THR = send;
}
int main()
{
	unsigned int j;
	unsigned char arr[]={"Team 9"};
	InitTimer0();  	
	T0TCR = 0x01;
	while(1)
	{
		while(!(T0IR==0x01));
		T0IR=0x01;
		for(j=0;j<6;j++)
		{
			sendUART(arr[j]);
		}
		sendUART('\n');
	}
}
