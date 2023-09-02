#include <lpc21xx.h>
void delay(int c)
{
	int i;
	for(i=0;i<c;i++);
}
void disp(int m)
{
	int j;
	int arr[16]={0x003F0000,0x00060000,0x005B0000,0x004F0000,0x00660000,0x006D0000,0x007D0000,0x00070000,0x007F0000,0x006F0000,0x00770000,0x007C0000,0x00390000,0x005E0000,0x00790000,0x00710000};
	j=m;
	IOCLR0=arr[j];
	delay(50000);
	IOSET0=arr[j];
	delay(50000);
	IOCLR0=arr[j];
}
int main()
{
	int i,val;
	unsigned int row0[4]={0x00EE0000,0x00DE0000,0x00BE0000,0x007E0000};
	unsigned int row1[4]={0x00ED0000,0x00DD0000,0x00BD0000,0x007D0000};
	unsigned int row2[4]={0x00EB0000,0x00DB0000,0x00BB0000,0x007B0000};
	unsigned int row3[4]={0x00E70000,0x00D70000,0x00B70000,0x00770000};
	PINSEL1=0X00000000;
	IODIR1=0XFFF0FFFF;
	IODIR0=0XF0FF0000;
	IOSET0=0XF0000000;
	while(1)
	{
		IOSET1=0X00FF0000;
		IOCLR1=0X00100000;
		val=IOPIN1;
		delay(30000);
		val=val & 0X00FF0000;
		for(i=0;i<4;i++)
		{
			if(row0[i]==val)
			{
				disp(i);
				delay(40000);
			}
		}

		IOSET1=0X00FF0000;
		IOCLR1=0X00200000;
		val=IOPIN1;
		delay(30000);
		val=val & 0X00FF0000;
		for(i=0;i<4;i++)
		{
			if(row1[i]==val)
			{
				disp(i+4);
				delay(40000);
			}
		}

		IOSET1=0X00FF0000;
		IOCLR1=0X00400000;
		val=IOPIN1;
		delay(30000);
		val=val & 0X00FF0000;
		for(i=0;i<4;i++)
		{
			if(row2[i]==val)
			{
				disp(i+8);
				delay(40000);
			}
		}

		IOSET1=0X00FF0000;
		IOCLR1=0X00800000;
		val=IOPIN1;
		delay(30000);
		val=val & 0X00FF0000;
		for(i=0;i<4;i++)
		{
			if(row3[i]==val)
			{
				disp(i+12);
				delay(40000);
			}
		}
	}
}
