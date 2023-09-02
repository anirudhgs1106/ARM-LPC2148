//First 10 fibonacci display on LCD
#include <lpc21xx.h>
#include <stdio.h>
void wr_cn(void);
void wr_dn(void);
void lcd_init(void);
void lcd_com(void);
void lcd_data(void);
void clr_disp(void);
void delay(unsigned int);
unsigned long int temp;
unsigned char temp1,c;
unsigned int i,n1=0,n2=1,n3,j;
int main()
{
	IODIR1=0x000000FC;
	lcd_init();
	delay(3200);
	clr_disp();
	delay(3200);
	temp=0x80;
	lcd_com();
	delay(3200);
	c=n1+0;
	temp1=c;
	lcd_data();
	c=n2+0;
	temp1=c;
	lcd_data();
	for(i=2;i<10;i++)
	{
		n3=n1+n2;
		c=n3+0;
		temp1=c;
		lcd_data();
		n1=n2;
		n2=n3;
	}
}
void delay(unsigned int r1)
{
	unsigned int r;
	for(r=0;r<r1;r++);
}
void lcd_init()
{
	unsigned int arr[4]={0x30,0x30,0x30,0x20};
	unsigned char arr1[4]={0x28,0x0C,0x06,0x80};
	for(j=0;j<4;j++)
	{
		temp=arr[j];
		wr_cn();
		delay(3200);
	}
	for(j=0;j<4;j++)
	{
		temp1=arr1[j];
		lcd_com();
		delay(3200);
	}
}
void wr_cn()
{
	IOCLR0=0x000000FC;
	IOSET0=temp;
	IOCLR0=0x00000004;
	IOSET0=0x00000008;
	delay(10);
	IOCLR0=0x00000008;
}
void wr_dn()
{
	IOCLR0=0x000000FC;
	IOSET0=temp;
	IOSET0=0x00000004;
	IOSET0=0x00000008;
	delay(10);
	IOCLR0=0x00000008;
}
void lcd_com()
{
	temp=temp1 & 0xF0;
	wr_cn();
	temp=temp1 & 0x0F;
	temp=temp << 4;
	wr_cn();
	delay(100);
}
void lcd_data()
{
	temp=temp1 & 0xF0;
	wr_dn();
	temp=temp1 & 0x0F;
	temp=temp << 4;
	wr_dn();
	delay(100);
}
void clr_disp()
{
	temp1=0x01;
	lcd_com();
	delay(100);
}
