#include"reg52.h"
#include"intrins.h"
typedef unsigned int u16;
typedef unsigned char u8;

#define LED_PORT	P2


void delay_10us(u16 ten_us)
{
	while(ten_us--);
	
}

void main(){
  u8 i=0;
	while(1){ 
	  for(i=0;i<8;i++)
		{
		LED_PORT=~(0x01<<i); //fe 16 jin zhi 1111 1110
		delay_10us(50000);
		}
	}
}