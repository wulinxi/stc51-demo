#include "reg52.h"
#include "intrins.h"

typedef unsigned int u16;
typedef unsigned char u8;
#define LED_PORT P2

void delay_ms(u16 ms)
{
    u16 i, j;
    for (i = ms; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}

void main()
{
    while (1)
    {
        // 中文测试
        LED_PORT = 0xAA; // 10101010
        delay_ms(500);   // ??500ms

        // ?????:X??X??X??X?? (0x55)
        LED_PORT = 0x55; // 01010101
        delay_ms(500);   // ??500ms
    }
}