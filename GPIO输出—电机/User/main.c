/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试电动机
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 IOT STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://fire-stm32.taobao.com  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "./motor/bsp_motor.h"   

void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	/* MOTOR GPIO 初始化 */
	Motor_GPIO_Config();	
	
	while(1)
	{		
		MOTOR( ON ); 			  // 响
		Delay(0x0FFFFFF);	
		MOTOR( OFF );		  // 不响
		Delay(0x0FFFFFF);
	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
