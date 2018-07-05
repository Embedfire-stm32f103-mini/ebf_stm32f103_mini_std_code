/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "./led/bsp_led.h" 
#include "./usart/bsp_usart.h" 

static void Show_Message(void);
  
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  char ch;
  
  /* LED GPIO 初始化 */
  LED_GPIO_Config();
  
  /* 初始化USART 配置模式为 115200 8-N-1 */
  USART_Config();
	
  /* 打印指令输入提示信息 */
  Show_Message();
  while(1)
	{	
    /* 获取字符指令 */
    ch=getchar();
    printf("接收到字符：%c\n",ch);
    
    /* 根据字符指令控制RGB彩灯颜色 */
    switch(ch)
    {
      case '1':
        LED1_ON;
      break;
      case '2':
        LED2_ON;
      break;
      case '3':
        LED1_OFF;
				LED2_OFF;
      break;
      default:
        /* 如果不是指定指令字符，打印提示信息 */
        Show_Message();
        break;      
    }   
	}	
}


/**
  * @brief  打印指令输入提示信息
  * @param  无
  * @retval 无
  */
static void Show_Message(void)
{
  printf("\r\n   这是一个通过串口通信指令控制LED灯实验 \n");
  printf("使用  USART  参数为：%d 8-N-1 \n",DEBUG_USART_BAUDRATE);
  printf("开发板接到指令后控制LED灯颜色，指令对应如下：\n");
  printf("   指令   ------ LED灯号 \n");
  printf("     1    ------    LED1 \n");
  printf("     2    ------    LED2 \n");
  printf("     3    ------    灭 \n");  
}

/*********************************************END OF FILE**********************/
