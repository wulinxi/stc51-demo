# 51单片机学习日记：从环境搭建到点亮第一个LED

## 2025年5月22日 星期四

今天是我正式开始学习51单片机的第一天，记录一下学习过程和收获。

### 一、开发环境搭建

首先下载并安装了Keil uVision5开发环境，这是学习51单片机最常用的IDE之一。

**安装步骤：**
1. 从官网下载Keil uVision5安装包
2. 按照向导完成基本安装
3. 安装C51编译器（注意不是ARM版本）
4. 使用注册机完成软件激活（学习用途）


### 二、第一个LED实验

环境搭建好后，迫不及待想看到实际效果。我使用的是STC89C52RC开发板，上面有一排LED。

**操作步骤：**
1. 连接开发板与电脑（使用USB转TTL烧写器）
2. 新建Keil工程，选择正确的单片机型号
3. 编写简单的LED控制程序：

```c
#include <reg52.h>

sbit LED1 = P1^0; // 定义P1.0口为LED1

void main() {
    LED1 = 0; // 低电平点亮LED（共阳接法）
    while(1);
}
```

4. 编译生成HEX文件
5. 使用STC-ISP烧录软件将程序下载到开发板
6. 看到第一个LED成功点亮！🎉

### 三、跑马灯实验

成功点亮单个LED后，我尝试了更复杂的跑马灯效果。

**实现代码：**

```c
#include "reg52.h"
#include "intrins.h"
typedef unsigned int u16;
typedef unsigned char u8;
#define LED_PORT	P2	

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void main()
{	
   	u8 i=0;

	LED_PORT=~0x01;
	delay_10us(50000);
	while(1)
	{
		for(i=0;i<7;i++)	 
		{									  
			LED_PORT=_crol_(LED_PORT,1);
			delay_10us(50000); 	
		}
		for(i=0;i<7;i++)	
		{
			LED_PORT=_cror_(LED_PORT,1);
			delay_10us(50000);	
		}	
	}		
}
```

**效果：** 开发板上的8个LED依次点亮，形成左右来回流动的效果。

### 四、遇到的问题及解决

1. **烧录失败**：第一次连接时无法识别端口
   - 解决：安装了正确的CH340驱动后正常

2. **LED不亮**：程序下载成功但LED没反应
   - 解决：发现开发板是共阳接法，需要给低电平才能点亮
