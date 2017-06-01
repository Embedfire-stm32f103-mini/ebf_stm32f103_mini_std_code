#ifndef __STM32F10X_H
#define __STM32F10X_H

// 用来存放STM32寄存器映射的代码

// 外设  perirhral

#define  PERIPH_BASE               ((unsigned int)0x40000000)
#define  APB1PERIPH_BASE           PERIPH_BASE
#define  APB2PERIPH_BASE          (PERIPH_BASE + 0x10000)
#define  AHBPERIPH_BASE           (PERIPH_BASE + 0x20000)


#define  RCC_BASE                (AHBPERIPH_BASE + 0x1000)
#define  GPIOC_BASE              (APB2PERIPH_BASE + 0x1000)


#define  RCC_APB2ENR            *(unsigned int*)(RCC_BASE + 0x18)
	
#define  GPIOC_CRL              *(unsigned int*)(GPIOC_BASE + 0x00)
#define  GPIOC_CRH              *(unsigned int*)(GPIOC_BASE + 0x04)
#define  GPIOC_IDR              *(unsigned int*)(GPIOC_BASE + 0x08)
#define  GPIOC_ODR              *(unsigned int*)(GPIOC_BASE + 0x0C)
#define  GPIOC_BSRR             *(unsigned int*)(GPIOC_BASE + 0x10)
#define  GPIOC_BRR              *(unsigned int*)(GPIOC_BASE + 0x14)
#define  GPIOC_LCKR             *(unsigned int*)(GPIOC_BASE + 0x18)
	
typedef unsigned int      uint32_t;
typedef unsigned short    uint16_t;

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIO_TypeDef;


typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
}RCC_TypeDef;


#define GPIOC   ((GPIO_TypeDef*)GPIOC_BASE)
#define RCC     ((RCC_TypeDef*)RCC_BASE)

#endif /* __STM32F10X_H */





















