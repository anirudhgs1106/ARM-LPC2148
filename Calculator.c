#include<lpc21xx.h>
#include<stdlib.h>
#include<stdio.h>
unsigned char input[6],InvalidMsg[]={" Invalid Operator!!"},msg[]={" Enter two Numbers : "};
char res[2];
unsigned int i;
int result;
void serial()
{
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x61;
	U0LCR=0x03;
}
void delay()
{
	for(i=0;i<100000;i++);
}

void getInput()
{
	for(i=0;i<4;i++)
	{
		while(!(U0LSR&0x01)); //Receive
		input[i]=U0RBR;
		U0THR=input[i];
		if(input[i]=='=')break;
	}
	if(input[3]!='=')exit(0);
}

void calculate()
{
	switch(input[1])
	{
		case '+':result=(input[0]+input[2])-96;break;
		case '-':result=(input[0]-input[2]);break;
		case '*':result=(input[0]-48)*(input[2]-48);break;
		case '/':result=(input[0]-48)/(input[2]-48);break;
		default:for(i=0;i<20;i++) //Transmit
						{
							while(!(U0LSR&0x20));
							U0THR=InvalidMsg[i];
							result=0;
						}
	}
	sprintf(res,"%d",result);
}
void printResult()
{
	for(i=0;i<3;i++) //Transmit
	{
		while(!(U0LSR&0x20));
		U0THR=res[i];
	}
	while(!(U0LSR&0x20)){}
		U0THR=10;
	while(!(U0LSR&0x20)){}
		U0THR=13;
	
}

int main()
{
	serial();
	while(1)
	{
		for(i=0;i<22;i++)
		{
			while(!(U0LSR&0x20));
			U0THR=msg[i];
		}
		getInput();
		calculate();
		printResult();
	}
}