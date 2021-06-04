#include "sys.h"
#include "delay.h" 
#include "led.h"
#include "key.h"
//ALIENTEK ������STM32F429������ ʵ��1
//�����ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
u8 key;

int main(void)
{ 
	Stm32_Clock_Init(360,25,2,8);//����ʱ��,180Mhz
	delay_init(180);		//��ʼ����ʱ����
	uart_init(90,115200);//��ʼ������
	LED_Init();				//��ʼ��LEDʱ��  
	KEY_Init();       //��ʼ��KEYʱ��
/*	while(1)
	{
		LED0=0;				//DS0��
		LED1=1;				//DS1��
		delay_ms(500);
		LED0=1;				//DS0��
		LED1=0;				//DS1��
		delay_ms(500);
	}
*/
	LED0=0;					//�ȵ������  
	while(1)
	{
		key=KEY_Scan(0); 	//�õ���ֵ
	  if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//����LED0,LED1�������
					LED1=!LED1;
					LED0=!LED1;
					break;
				case KEY2_PRES:	//����LED0��ת
					LED0=!LED0;
					break;
				case KEY1_PRES:	//����LED1��ת	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}
}

















