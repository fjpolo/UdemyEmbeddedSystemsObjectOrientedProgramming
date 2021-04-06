#include "my_stm32f407_gpio_lib.h"

/**
* Defines
*/
#define GPIO_NUMBER				(16U)
#define GPIO_MODER_MODER0	(0x3U<<0)
#define GPIO_MODE					(0x03U)
#define GPIO_PUPDR_PUPDR0	(0x3U<<0)

/**
* Functions
*/
void LIB_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
	uint32_t position;
  uint32_t ioposition = 0x00U;
  uint32_t iocurrent = 0x00U;
  uint32_t temp = 0x00U;
	
	/*Configure the port pins*/
	for(position=0U; position<GPIO_NUMBER; position++){
		/* Get the IO position */
    ioposition = 0x01U << position;
    /* Get the current IO position */
    iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;
		
		/**/
		if(iocurrent == ioposition){
			/* Configure IO Direction mode (Input, Output) */
      temp = GPIOx->MODER;
      temp &= ~(GPIO_MODER_MODER0 << (position * 2U));
      temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U));
      GPIOx->MODER = temp;
			
		  /* Activate the Pull-up or Pull down resistor for the current IO */
      temp = GPIOx->PUPDR;
      temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
      temp |= ((GPIO_Init->Pull) << (position * 2U));
      GPIOx->PUPDR = temp;
		} // END if    
	} // END for
} // END LIB_GPIO_Init
	
GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	GPIO_PinState BitStatus;
	
	/*Read*/
	if( (GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET){
		BitStatus = GPIO_PIN_SET;
	} // END if
	else BitStatus = GPIO_PIN_RESET;
	
	/*Return*/
	return BitStatus;
} // END LIB_GPIO_ReadPin
	
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
	/**/
	if( (PinState) != GPIO_PIN_RESET ){
		GPIOx->BSRR = GPIO_Pin;
	} // END if
	else{
		GPIOx->BSRR = (uint32_t)GPIO_Pin<<16U;
	} // END else
} // END LIB_GPIO_WritePin

void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	/*Toggle*/
	GPIOx->ODR ^= GPIO_Pin;
} // END LIB_GPIO_TogglePin
void __LIB_RCC_GPIOA_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOA_EN;}
void __LIB_RCC_GPIOB_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOB_EN;}
void __LIB_RCC_GPIOC_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOC_EN;}
void __LIB_RCC_GPIOD_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOD_EN;}
void __LIB_RCC_GPIOE_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOE_EN;}
void __LIB_RCC_GPIOF_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOF_EN;}
void __LIB_RCC_GPIOG_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOG_EN;}
void __LIB_RCC_GPIOH_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOH_EN;}
void __LIB_RCC_GPIOI_CLK_ENABLE(void){RCC->AHB1ENR |= GPIOI_EN;}