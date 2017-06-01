/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   dht11温湿度传感器测试实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "./systick/bsp_SysTick.h"
#include "./dht11/bsp_dht11.h"
#include "./usart/bsp_usart.h"



/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	DHT11_Data_TypeDef DHT11_Data;
	
	
	/* 配置SysTick 为1us中断一次 */
	SysTick_Init();

	USART_Config();//初始化串口1
	printf("\r\n***秉火STM32 dht11 温湿度传感器实验***\r\n");

	/*初始化DTT11的引脚*/
	DHT11_Init ();
	
	while(1)
	{	
			/*调用DHT11_Read_TempAndHumidity读取温湿度，若成功则输出该信息*/
			if( DHT11_Read_TempAndHumidity ( & DHT11_Data ) == SUCCESS)
			{
				printf("\r\n读取DHT11成功!\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
				DHT11_Data.humi_int,DHT11_Data.humi_deci,DHT11_Data.temp_int,DHT11_Data.temp_deci);
			}			
			else
			{
				printf("Read DHT11 ERROR!\r\n");
			}
			
		 Delay_ms(1000);
	}

	
}
/*********************************************END OF FILE**********************/
