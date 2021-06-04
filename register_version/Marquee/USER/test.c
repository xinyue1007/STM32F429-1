#include "sys.h"
#include "delay.h" 
#include "led.h"
#include "key.h"
//ALIENTEK 阿波罗STM32F429开发板 实验1
//跑马灯实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
u8 key;

int main(void)
{ 
	Stm32_Clock_Init(360,25,2,8);//设置时钟,180Mhz
	delay_init(180);		//初始化延时函数
	uart_init(90,115200);//初始化串口
	LED_Init();				//初始化LED时钟  
	KEY_Init();       //初始化KEY时钟
/*	while(1)
	{
		LED0=0;				//DS0亮
		LED1=1;				//DS1灭
		delay_ms(500);
		LED0=1;				//DS0灭
		LED1=0;				//DS1亮
		delay_ms(500);
	}
*/
	LED0=0;					//先点亮红灯  
	while(1)
	{
		key=KEY_Scan(0); 	//得到键值
	  if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//控制LED0,LED1互斥点亮
					LED1=!LED1;
					LED0=!LED1;
					break;
				case KEY2_PRES:	//控制LED0翻转
					LED0=!LED0;
					break;
				case KEY1_PRES:	//控制LED1翻转	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}
}

















