#include"reg52.h"
#include"intrins.h"
typedef unsigned int u16;
typedef unsigned char u8;

sbit BEEP=P2^5;


void delay_10us(u16 ten_us)
{
	while(ten_us--);
	
}

void main()
{
  u16 i=2000;
	while(1)
		{ 
	  while(i--)
			{
		BEEP = !BEEP;//mai chong xinhao
			delay_10us(200);//zhouqi
		}
		i=0;
		BEEP=0;
	  }
}