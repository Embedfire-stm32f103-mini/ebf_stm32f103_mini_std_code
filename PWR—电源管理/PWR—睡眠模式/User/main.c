/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   睡眠模式例程
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 MINI 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_usart.h"
#include "./Key/bsp_exti.h"


static void Delay(__IO u32 nCount);


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{ 
	
	LED_GPIO_Config();	
	
  /*初始化USART1*/
  USART_Config();		
	
	/* 初始化按键为中断模式，按下中断后会进入中断服务函数	*/
	EXTI_Key_Config(); 
	
	printf("\r\n 欢迎使用秉火  STM32  开发板。\r\n");
  printf("\r\n 秉火STM32 睡眠模式例程\r\n");
	
	printf("\r\n 实验说明：\r\n");

	printf("\r\n 1.程序运行一段时间后自动进入睡眠状态，在睡眠状态下，可使用KEY1或KEY2唤醒\r\n");
	printf("\r\n 2.本实验执行这样一个循环：\r\n ------》正常运行->睡眠模式->按KEY1或KEY2唤醒->刚被唤醒-----》\r\n");
	printf("\r\n 3.在睡眠状态下，DAP下载器无法给STM32下载程序，\r\n 可按KEY1、KEY2唤醒后下载，\r\n 或按复位键使芯片处于复位状态，然后在电脑上点击下载按钮，再释放复位按键，即可下载\r\n");

  while(1)
  {	
		/*********执行任务***************************/
		printf("\r\n STM32正常运行\r\n");
	
		LED1_OFF;
		LED2_ON;	
		Delay(0x3FFFFF);
		
		/*****任务执行完毕，进入睡眠降低功耗***********/
		
		
		printf("\r\n 进入睡眠模式，按KEY1或KEY2按键可唤醒\r\n");

		//使用LED1指示，进入睡眠状态
		LED2_OFF;
		LED1_ON;
		//进入睡眠模式
		__WFI();	//WFI指令进入睡眠
		
		//等待中断唤醒  K1或K2按键中断	
		
		/***被唤醒，亮LED2指示***/
		LED1_OFF;
		LED2_ON;	
		Delay(0x1FFFFF);		
			
		printf("\r\n 已退出睡眠模式\r\n");
		//继续执行while循环

  }

}

static void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}



/*********************************************END OF FILE**********************/
