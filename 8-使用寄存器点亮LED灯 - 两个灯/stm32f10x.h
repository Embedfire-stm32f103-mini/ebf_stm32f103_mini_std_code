

/*本文件用于添加寄存器地址及结构体定义*/

/*片上外设基地址  */
#define PERIPH_BASE           ((unsigned int)0x40000000)

/*APB2 总线基地址 */
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
/* AHB总线基地址 */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

/*GPIOC外设基地址*/
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)

/* GPIOC寄存器地址,强制转换成指针 */
#define GPIOC_CRL			*(unsigned int*)(GPIOC_BASE+0x00)
#define GPIOC_CRH			*(unsigned int*)(GPIOC_BASE+0x04)
#define GPIOC_IDR			*(unsigned int*)(GPIOC_BASE+0x08)
#define GPIOC_ODR			*(unsigned int*)(GPIOC_BASE+0x0C)
#define GPIOC_BSRR	  *(unsigned int*)(GPIOC_BASE+0x10)
#define GPIOC_BRR			*(unsigned int*)(GPIOC_BASE+0x14)
#define GPIOC_LCKR		*(unsigned int*)(GPIOC_BASE+0x18)

/*RCC外设基地址*/
#define RCC_BASE      (AHBPERIPH_BASE + 0x1000)
/*RCC的AHB1时钟使能寄存器地址,强制转换成指针*/
#define RCC_APB2ENR		 *(unsigned int*)(RCC_BASE+0x18)

