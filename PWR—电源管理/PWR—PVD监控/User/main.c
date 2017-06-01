/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   PVD电源监控实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./key/bsp_key.h" 
#include "./usart/bsp_usart.h"
#include "./pvd/bsp_pvd.h"



/*
*【 ！】实验操作：
* 1.使用外部可调电源，调节成5V输出，连接到实验板引出的 5V<--->GND排针给板子供电；
*2.复位实验板，电压正常时板子上的LED彩灯应为绿色
*3.向下调节可调电源的电压，大约当降至4.2V的时候，LED彩灯会转为红色。
*（程序中控制PVD监控电压约为2.6V,当5V电源降至4.2V的时候，连接STM32的VDD电源(3.3V电源)会低于2.5V，产生PVD事件，在中断中控制亮红灯）
*/

/*【 ！！】注意事项：
*使用可调电源给实验板供电，其它电源线都拔掉(包括下载器、USB线)。
*由于直接接排针供电没有电路保护，调节电源时小心不要使供电电压远高于5V,电压太高会烧坏实验板！！
*/
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{	
		LED_GPIO_Config();	
	
	//亮灯1，表示正常运行
	LED1_ON; 
	
	//配置PVD，当电压过低时，会进入中断服务函数，亮红灯
	PVD_Config();
	
  while(1)
  {			
		
		/*正常运行的程序*/

  }
}



/*********************************************END OF FILE**********************/
