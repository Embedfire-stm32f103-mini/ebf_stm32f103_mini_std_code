/**
  ******************************************************************************
  * @file    bsp_motor.c
  * @author  fire
  * @version V3.0
  * @date    2015-xx-xx
  * @brief   电动机应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 IOT STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./motor/bsp_motor.h"   

 /**
  * @brief  初始化控制电动机的IO
  * @param  无
  * @retval 无
  */
void Motor_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启控制电动机的GPIO的端口时钟*/
		RCC_APB2PeriphClockCmd( MOTOR_GPIO_CLK, ENABLE); 

		/*选择要控制电动机的GPIO*/															   
		GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PIN;	

		/*设置GPIO模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置GPIO速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化控制蜂鸣器的GPIO*/
		GPIO_Init(MOTOR_GPIO_PORT, &GPIO_InitStructure);			 
    
    /* 关闭电动机*/
		GPIO_ResetBits(MOTOR_GPIO_PORT, MOTOR_GPIO_PIN);	 
}
/*********************************************END OF FILE**********************/
