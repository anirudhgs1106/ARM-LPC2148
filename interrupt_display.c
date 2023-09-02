//"Interrupt occured" if interrupt triggered else "No interrupt"
#include <lpc21xx.h>
#include <stdio.h>
unsigned char temp1;
unsigned int temp,i;
unsigned char *ptr,*ptr1,disp[]="Interrupt Occured",disp1[]="No interrupt";
void wr_cn(void);
void wr_dn(void);
void lcd_init(void);
void lcd_com(void);
void lcd_data(void);
void clr_disp(void);
void delay(unsigned int);
void extint0_isr(void)__irq;
int main()
{
	PINSEL1=0x00000001;
	IODIR0=0x000000FC;
	lcd_init();
	delay(3200);
	clr_disp();
	delay(3200);
	temp1=0x80;
	lcd_com();
	ptr=disp1;
	while(*ptr!='\0')
	{
		temp1=*ptr;
		lcd_data();
		ptr++;
	}
	EXTMODE=0x01;
	VICVectAddr0=(unsigned long)extint0_isr;
	VICVectCntl0=0x20|14;
	VICIntEnable=0x00004000;
	while(1);
}
void extint0_isr(void)__irq
{
	ptr1=disp;
	while(*ptr1!='\0')
	{
		temp1=*ptr1;
		lcd_data();
		ptr1++;
	}
	EXTINT=0x01;
	VICVectAddr0=0x00;
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
	for(i=0;i<4;i++)
	{
		temp=arr[i];
		wr_cn();
		delay(3200);
	}
	for(i=0;i<4;i++)
	{
		temp1=arr1[i];
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
void clr_disp()
{
	temp=0x01;
	lcd_com();
	delay(500);
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
void lcd_com()
{
	temp=temp1 & 0xF0;
	wr_cn();
	temp=temp1 & 0x0F;
	temp=temp << 4;
	wr_cn();
	delay(100);
}
