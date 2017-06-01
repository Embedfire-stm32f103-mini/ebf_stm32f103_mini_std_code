
//#if 0

//#include <rge52.h>

//sbit LED  = P0^0

//void main(void)
//{
//	P0 = 0XFE;     // 总线操作  sfr P0   0X80
//	
//	LED = 0;       // 位操作
//}

//#endif



#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

int main (void)
{
#if 0	
	// 打开 GPIOC 端口的时钟
	*( unsigned int * )0x40021018 |=  ( (1) << 4 );
	
	// 配置IO口为输出
	*( unsigned int * )0x40011000 &=  ~( (0x0f) << (4*2) );
	*( unsigned int * )0x40011000 |=  ( (1) << (4*2) );
	
	// 控制 ODR 寄存器
	*( unsigned int * )0x4001100c &= ~(1<<2);
	
#elif 0
	
	// 打开 GPIOC 端口的时钟
	RCC_APB2ENR  |=  ( (1) << 4 );
	
	// 配置IO口为输出
	GPIOC_CRL &=  ~( (0x0f) << (4*2) );
	GPIOC_CRL |=  ( (1) << (4*2) );
	
	// 控制 ODR 寄存器
	GPIOC_ODR &= ~(1<<2);
	//GPIOC_ODR |= (1<<2);
	
	
#elif 1
		// 打开 GPIOC 端口的时钟
	RCC->APB2ENR  |=  ( (1) << 4 );
	
	// 配置IO口为输出
	GPIOC->CRL &=  ~( (0x0f) << (4*2) );
	GPIOC->CRL |=  ( (1) << (4*2) );
	
	GPIO_SetBits(GPIOC,GPIO_Pin_2);
	GPIO_ResetBits( GPIOC,GPIO_Pin_2 );
#endif
}


void SystemInit(void)
{
	// 函数体为空，目的是为了骗过编译器不报错
}








