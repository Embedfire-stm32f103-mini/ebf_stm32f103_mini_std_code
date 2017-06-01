/**
  ******************************************************************************
  * @file    OLED_I2C.c
  * @author  fire
  * @version V1.0
  * @date    2014-xx-xx
  * @brief   128*64点阵的OLED显示测试工程，仅适用于SD1306驱动IIC通信方式显示屏
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 ISO STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
	*
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "delay.h"

extern const unsigned char BMP1[];

int main(void)
{
	unsigned char i;

	
	DelayInit();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//全屏点亮
		DelayS(2);
		OLED_Fill(0x00);//全屏灭
		DelayS(2);
		for(i=0;i<4;i++)
		{
			OLED_ShowCN(22+i*16,0,i);									//测试显示中文
		}
		DelayS(2);
		OLED_ShowStr(0,3,(unsigned char*)"Wildfire Tech",1);				//测试6*8字符
		OLED_ShowStr(0,4,(unsigned char*)"Hello wildfire",2);				//测试8*16字符
		DelayS(200);
		OLED_CLS();//清屏
		OLED_OFF();//测试OLED休眠
		DelayS(2);
		OLED_ON();//测试OLED休眠后唤醒
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//测试BMP位图显示
		DelayS(20);
	}
}
