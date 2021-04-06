#ifndef __MY_STM32F407_GPIO_DRIVERS_H
#define __MY_STM32F407_GPIO_DRIVERS_H

#include <stdint.h>
/**
 * 
 */
//#define             PERIPH_BASE             0x40000000U                         // APB1 Base
//#define             AHB1PERIPH_BASE         (PERIPH_BASE + 0x20000U)            // 0x4002 0000
#define 						PERIPH_BASE           	0x40000000UL /*!< Peripheral base address in the alias region                                */
#define 						APB1PERIPH_BASE       	PERIPH_BASE
#define 						APB2PERIPH_BASE       	(PERIPH_BASE + 0x00010000UL)
#define 						AHB1PERIPH_BASE       	(PERIPH_BASE + 0x00020000UL)
#define 						AHB2PERIPH_BASE       	(PERIPH_BASE + 0x10000000UL)
#define             RCC_BASE                (AHB1PERIPH_BASE + 0x3800U)         // 0x4002 3800
#define             GPIOA_BASE              (AHB1PERIPH_BASE + 0x00U)						// 0x4002 0000
#define             GPIOB_BASE              (AHB1PERIPH_BASE + 0x400U)					// 0x4002 0400
#define             GPIOC_BASE              (AHB1PERIPH_BASE + 0x800U)					// 0x4002 0800
#define             GPIOD_BASE              (AHB1PERIPH_BASE + 0xC00U)					// 0x4002 0C00
#define             GPIOE_BASE              (AHB1PERIPH_BASE + 0x1000U)					// 0x4002 1000
#define             GPIOF_BASE              (AHB1PERIPH_BASE + 0x1400U)					// 0x4002 1400
#define             GPIOG_BASE              (AHB1PERIPH_BASE + 0x1800U)					// 0x4002 1800
#define             GPIOH_BASE              (AHB1PERIPH_BASE + 0x1C00U)					// 0x4002 1C00
#define             GPIOI_BASE              (AHB1PERIPH_BASE + 0x2000U)         // 0x4002 1C00

/**
 * 
 */
#define             __IO                    volatile

/**
 * 
 */

/*GPIO_TypeDef*/
#ifndef GPIO_TypeDef
typedef struct{
    __IO    uint32_t    MODER;          // GPIO port mode register
    __IO    uint32_t    OTYPER;
    __IO    uint32_t    OSPEEDR;    
    __IO    uint32_t    PUPDR;
    __IO    uint32_t    IDR;
    __IO    uint32_t    ODR;
    __IO    uint32_t    BSRR;
    __IO    uint32_t    LCKR;
    __IO    uint32_t    AFL[2]; 
}GPIO_TypeDef;
#endif // GPIO_TypeDef

/*RCC_TypeDef*/
#ifndef RCC_TypeDef
typedef struct{
    __IO    uint32_t    CR;             // RCC clock control register
    __IO    uint32_t    PLLCFGR;        // RCC PLL configuration register
    __IO    uint32_t    CFGR;           // RCC clock configuration register
    __IO    uint32_t    CIR;            // RCC clock interrupt register
    __IO    uint32_t    AHB1RSTR;       // RCC AHB1 peripheral reset register
    __IO    uint32_t    AHB2RSTR;       // RCC AHB2 peripheral reset register
    __IO    uint32_t    AHB3RSTR;       // RCC AHB3 peripheral reset register
    __IO    uint32_t    DUMMY1;         // Dummy 32 bits
    __IO    uint32_t    APB1RSTR;       // RCC APB1 peripheral reset register
    __IO    uint32_t    APB2RSTR;       // RCC APB2 peripheral reset register
    __IO    uint32_t    DUMMY2;         // Dummy 32 bits
    __IO    uint32_t    DUMMY3;         // Dummy 32 bits
    __IO    uint32_t    AHB1ENR;        // RCC AHB1 peripheral clock enable register
    __IO    uint32_t    AHB2ENR;        // RCC AHB2 peripheral clock enable register
    __IO    uint32_t    AHB3ENR;        // RCC AHB3 peripheral clock enable register
    __IO    uint32_t    DUMMY4;         // Dummy 32 bits
    __IO    uint32_t    APB1ENR;        // RCC APB1 peripheral clock enable register
    __IO    uint32_t    APB2ENR;        // RCC APB2 peripheral clock enable register
    __IO    uint32_t    DUMMY5;         // Dummy 32 bits
    __IO    uint32_t    DUMMY6;         // Dummy 32 bits
    __IO    uint32_t    AHB1LPENR;      // RCC AHB1 peripheral clock enable in low power mode register     
    __IO    uint32_t    AHB2LPENR;      // RCC AHB2 peripheral clock enable in low power mode register
    __IO    uint32_t    AHB3LPENR;      // RCC AHB3 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY7;         // Dummy 32 bits
    __IO    uint32_t    APB1LPENR;      // RCC APB1 peripheral clock enable in low power mode register
    __IO    uint32_t    APB2LPENR;      // RCC APB2 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY8;         // Dummy 32 bits
    __IO    uint32_t    DUMMY9;         // Dummy 32 bits
    __IO    uint32_t    BDCR;           // RCC Backup domain control register (
    __IO    uint32_t    CSR;            // RCC clock control & status register
    __IO    uint32_t    DUMMY10;        // Dummy 32 bits
    __IO    uint32_t    DUMMY11;        // Dummy 32 bits
    __IO    uint32_t    SSCGR;          // RCC spread spectrum clock generation register
    __IO    uint32_t    PLLI2SCFGR;     // RCC PLLI2S configuration register
    __IO    uint32_t    PLLSAICFGR;     // RCC PLL configuration register
    __IO    uint32_t    DCKCFGR;        // RCC Dedicated Clock Configuration Register 
}RCC_TypeDef;
#endif // RCC_TypeDef 

/**
 * 
 */
#define             RCC             ((RCC_TypeDef*)RCC_BASE)
#define             GPIOA           ((GPIO_TypeDef*)GPIOA_BASE)
#define             GPIOB           ((GPIO_TypeDef*)GPIOB_BASE)
#define             GPIOC           ((GPIO_TypeDef*)GPIOC_BASE)
#define             GPIOD           ((GPIO_TypeDef*)GPIOD_BASE)
#define             GPIOE           ((GPIO_TypeDef*)GPIOE_BASE)
#define             GPIOF           ((GPIO_TypeDef*)GPIOF_BASE)
#define             GPIOG           ((GPIO_TypeDef*)GPIOG_BASE)
#define             GPIOH           ((GPIO_TypeDef*)GPIOH_BASE)
#define             GPIOI           ((GPIO_TypeDef*)GPIOI_BASE)

/**
 * 
 */
#define             MODER_1_OUT             (1<<0)         
#define             MODER_2_OUT             (1<<2)         
#define             MODER_3_OUT             (1<<4)         
#define             MODER_4_OUT             (1<<8)         
#define             MODER_5_OUT             (1<<10)         
#define             MODER_6_OUT             (1<<12)         
#define             MODER_7_OUT             (1<<14)             
#define             MODER_8_OUT             (1<<16) 
#define             MODER_9_OUT             (1<<18) 
#define             MODER_10_OUT             (1<<20) 
#define             MODER_11_OUT             (1<<22) 
#define             MODER_12_OUT             (1<<24) 

/**
 * Enable Ports
 */
#define 						GPIOA_EN								(1<<0)
#define 						GPIOB_EN								(1<<1)
#define 						GPIOC_EN								(1<<2)
#define 						GPIOD_EN								(1<<3)
#define 						GPIOE_EN								(1<<4)
#define 						GPIOF_EN								(1<<5)
#define 						GPIOG_EN								(1<<6)
#define 						GPIOH_EN								(1<<7)
#define 						GPIOI_EN								(1<<8)

#endif // __MY_STM32F407_GPIO_DRIVERS_H
