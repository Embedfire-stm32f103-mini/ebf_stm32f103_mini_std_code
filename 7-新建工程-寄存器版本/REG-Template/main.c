#include "stm32f10x.h"

#define YHMINI 0
#define YHIOT  1

void soft_delay(unsigned int count)
{
	for( ;count!=0;count-- );
}

int main( void )
{
#if YHMINI
		// 打开 GPIOB 端口的时钟
	*( unsigned int * )0x40021018 |=  ( (1) << 4 );
	
	// 配置IO口为输出
	*( unsigned int * )0x40011000 |=  ( (1) << (4*2) );
	
	// 控制 ODR 寄存器
	*( unsigned int * )0x4001100C &= ~(1<<2);	
	
	while(1)
	{
		/* 亮 */	
		*( unsigned int * )0x4001100C &= ~(1<<2);
		soft_delay(0xfffff);
		
		/* 灭 */	
		*( unsigned int * )0x4001100C |= (1<<2);
		soft_delay(0xfffff);
	}

#elif YHIOT
			// 打开 GPIOB 端口的时钟
	*( unsigned int * )0x40021018 |=  ( (1) << 3 );
	
	// 配置IO口为输出
	*( unsigned int * )0x40010C00 |=  ( (1) << (4*0) );
	
	// 控制 ODR 寄存器
	*( unsigned int * )0x40010C0C &= ~(1<<0);
	
	while(1)
	{
		/* 亮 */	
		*( unsigned int * )0x40010C0C &= ~(1<<0);
		soft_delay(0xfffff);
		
		/* 灭 */	
		*( unsigned int * )0x40010C0C |= (1<<0);
		soft_delay(0xfffff);
	}	
#endif
}



void SystemInit(void)
{
	/* 函数体为空，为的是骗过编译器不报错 */
}
