
/*
	*工程模板(寄存器版本)
  */
#include "stm32f10x.h" 


/**
  *   主函数
  */
int main(void)
{	
	// 开启GPIOC 端口时钟
	RCC_APB2ENR |= (1<<4);

	//清空控制PC2的端口位
	GPIOC_CRL &= ~( 0x0F<< (4*2));	
	// 配置PC2为通用推挽输出，速度为10M
	GPIOC_CRL |= (1<<4*2);

	// PC2 输出 低电平
	GPIOC_ODR &= ~(1<<2);
	
	//清空控制PC3的端口位
	GPIOC_CRL &= ~( 0x0F<< (4*3));
	
	// 配置PC3为通用推挽输出，速度为10M
	GPIOC_CRL |= (1<<4*3);
	
	// PC3 输出 低电平
	GPIOC_ODR &= ~(1<<3);
	while(1);
}



// 函数为空，目的是为了骗过编译器不报错
void SystemInit(void)
{	
}






/*********************************************END OF FILE**********************/

