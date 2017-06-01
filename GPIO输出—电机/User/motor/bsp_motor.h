#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32f10x.h"


/* 定义蜂鸣器连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的蜂鸣器引脚 */
#define MOTOR_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define MOTOR_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define MOTOR_GPIO_PIN		  GPIO_Pin_8			        /* 连接到蜂鸣器的GPIO */

/* 高电平时，蜂鸣器响 */
#define ON  1
#define OFF 0

/* 带参宏，可以像内联函数一样使用 */
#define MOTOR(a)	if (a)	\
					GPIO_SetBits(MOTOR_GPIO_PORT,MOTOR_GPIO_PIN);\
					else		\
					GPIO_ResetBits(MOTOR_GPIO_PORT,MOTOR_GPIO_PIN)
					

/* 直接操作寄存器的方法控制IO */
#define digitalHi(p,i)			{p->BSRRL=i;}			  //设置为高电平		
#define digitalLo(p,i)			{p->BSRRH=i;}				//输出低电平
#define digitalToggle(p,i)	{p->ODR ^=i;}			//输出反转状态


/* 定义控制IO的宏 */
#define MOTOR_TOGGLE		digitalToggle(MOTOR_GPIO_PORT,BEEP_GPIO_PIN)
#define MOTOR_OFF				digitalLo(MOTOR_GPIO_PORT,BEEP_GPIO_PIN)
#define MOTOR_ON				digitalHi(MOTOR_GPIO_PORT,BEEP_GPIO_PIN)

void Motor_GPIO_Config(void);
					
#endif /* __BEEP_H */
