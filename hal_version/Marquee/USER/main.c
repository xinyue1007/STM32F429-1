#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

/************************************************
 ALIENTEK ������STM32F429������ʵ��0-1
 Template����ģ��-�½������½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


/***ע�⣺�����̺ͽ̳��е��½�����3.3С�ڶ�Ӧ***/


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

    u8 key;
    HAL_Init();                     //��ʼ��HAL��    
    Stm32_Clock_Init(360,25,2,8);   //����ʱ��,180Mhz

    delay_init(180);                //��ʼ����ʱ����
    uart_init(115200);              //��ʼ��USART
    LED_Init();                     //��ʼ��LED 
    KEY_Init();                     //��ʼ������

	while(1)
	{
        key=KEY_Scan(0);            //����ɨ��
				switch(key)
				{				 
					case  WKUP_PRES:	//����LED0,LED1�������
								LED1=!LED1; 
								LED0=!LED1;
								break;
					case  KEY2_PRES:	//����LED0��ת
								LED0=!LED0;
								break;
					case  KEY1_PRES:	//����LED1��ת	 
								LED1=!LED1;
								break;
					case  KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
								LED0=!LED0;
								LED1=!LED1;
								break;
			}
        delay_ms(10);
	}
	}

