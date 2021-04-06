#include <stdint.h>
/**
 * 
 */
#define             PERIPH_BASE             0x40000000U                         // APB1 Base
#define             AHB1PERIPH_BASE         (PERIPH_BASE + 0x20000U)            // 0x4002 0000
#define             RCC_BASE                (AHB1PERIPH_BASE + 0x3800U)         // 0x4002 3800
//#define             GPIOA_BASE              // 0x4002 0000
//#define             GPIOB_BASE              //
//#define             GPIOC_BASE              //
//#define             GPIOD_BASE              //
//#define             GPIOE_BASE              //
//#define             GPIOF_BASE              //
//#define             GPIOG_BASE              //
//#define             GPIOH_BASE              //
#define             GPIOI_BASE              (AHB1PERIPH_BASE + 0x1C00U)         // 0x4002 1C00

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
    __IO    uint32_t    PUDPR;
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
//#define             GPIOA           ((GPIO_TypeDef*)GPIOA_BASE)
//#define             GPIOB           ((GPIO_TypeDef*)GPIOB_BASE)
//#define             GPIOC           ((GPIO_TypeDef*)GPIOC_BASE)
//#define             GPIOD           ((GPIO_TypeDef*)GPIOD_BASE)
//#define             GPIOE           ((GPIO_TypeDef*)GPIOE_BASE)
//#define             GPIOF           ((GPIO_TypeDef*)GPIOF_BASE)
//#define             GPIOG           ((GPIO_TypeDef*)GPIOG_BASE)
//#define             GPIOH           ((GPIO_TypeDef*)GPIOH_BASE)
#define             GPIOI           ((GPIO_TypeDef*)GPIOI_BASE)

//#define             MODER_1_OUT         
//#define             MODER_2_OUT         
//#define             MODER_3_OUT         
//#define             MODER_4_OUT         
//#define             MODER_5_OUT         
//#define             MODER_6_OUT         
#define             MODER_7_OUT             (1<<14)             
//#define             MODER_8_OUT         

/**
 * Pins
 */
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

      
/**
 * 
 */
#define RED_LED_PORT					GPIOI
#define RED_LED_PIN						GPIO_PIN_7
#define GREEN_LED_PORT				GPIOB
#define GREEN_LED_PIN					GPIO_PIN_7
#define YELLOW_LED_PORT				GPIOG
#define YELLOW_LED_PIN				GPIO_PIN_11

int main(void){
  RCC->AHB1ENR |= 0x07;									// Enable GPIOI
	GPIOI->MODER |= MODER_7_OUT;					// 
	
	while(1){
		for(int i=0;i<1000000000;i++);
		GPIOI->ODR ^= RED_LED_PIN;					// Toggle LED 
	}
	
}	





