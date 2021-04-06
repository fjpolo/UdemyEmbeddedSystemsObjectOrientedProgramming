#include  "my_stm32f4_gpio_lib.h"

#define GPIO_NUMBER									16U
#define	GPIO_MODER_MODE0						0x3U<<0
#define	GPIO_MODE										0x03U
#define	GPIO_PUPDR_PUPDR0						0x3U<<0
#define	GPIO_OSPEEDER_OSPEEDR0			0x3U<<0
#define	GPIO_OTYPER_OT0							0x1U<<0
#define GPIO_OUTPUT_TYPE						0x00010U

void LIB_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_Init){

 uint32_t position;
 uint32_t temp =  0x0U;
 uint32_t ioposition = 0x00U;
 uint32_t iocurrent =  0x00U;
	
	for(position =0U; position <GPIO_NUMBER;position++){
		 
		ioposition = 0x01U << position;
		iocurrent =  (uint32_t)(GPIO_Init->Pin)&ioposition;
		
		if(iocurrent == ioposition){
		 /*Alternate function selection*/	
		if((GPIO_Init->Mode == GPIO_MODE_AF_PP) ||(GPIO_Init->Mode == GPIO_MODE_AF_OD)){
		
		 temp  =  GPIOx->AFR[position >>3U];
		 temp &= ~(0xFU <<((uint32_t)(position & 0x07U) * 4U));
		 temp |=((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & 0x07U)*4U)); 
		 GPIOx->AFR[position >>3U] =  temp;
		
		}
			
			/*Direction mode*/
		 temp  =  GPIOx->MODER;
		 temp &=~(GPIO_MODER_MODE0 <<(position * 2U));
		 temp |=(GPIO_Init->Mode & GPIO_MODE) <<(position *2U);
		 GPIOx->MODER =  temp;
		
		/*Alternate function selection*/
		if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode== GPIO_MODE_OUTPUT_OD)||
			  (GPIO_Init->Mode== GPIO_MODE_AF_PP) || (GPIO_Init->Mode== GPIO_MODE_AF_OD)){
			
		  temp =  GPIOx->OSPEEDR;
			temp &= ~(GPIO_OSPEEDER_OSPEEDR0 << (position *2U));
			temp |= (GPIO_Init->Speed <<(position *2U));
			GPIOx->OSPEEDR =temp;
					
					/*Output type*/
			temp =  GPIOx->OTYPER;
			temp &= ~(GPIO_OTYPER_OT0 << (position *2U));
			temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE)>> 4U) <<(position *2U));
			GPIOx->OTYPER =  temp;
		}
		
		 temp  =  GPIOx->PUPDR;
		 temp &=~(GPIO_PUPDR_PUPDR0 <<(position * 2U));
		 temp |=((GPIO_Init->Pull) << (position *2U));
		 GPIOx->PUPDR = temp;
			
			
		
		}
	 

	}
	
}


GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	 GPIO_PinState bitstatus;
	if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET){
	 bitstatus = GPIO_PIN_SET;
	}
	else{
	bitstatus = GPIO_PIN_RESET;
	}
	
	return bitstatus;
}


void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin,GPIO_PinState PinState)
{
	if(PinState != GPIO_PIN_RESET){
	  GPIOx->BSRR  =GPIO_Pin;
	}
	
	else{
	   GPIOx->BSRR = (uint32_t)GPIO_Pin <<16;
	}
}


void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin){

	 GPIOx->ODR ^= GPIO_Pin;
}

void __LIB_RCC_GPIOA_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOA_EN;}
void __LIB_RCC_GPIOB_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOB_EN;}
void __LIB_RCC_GPIOC_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOC_EN;}
void __LIB_RCC_GPIOD_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOD_EN;}
void __LIB_RCC_GPIOE_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOE_EN;}
void __LIB_RCC_GPIOH_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOH_EN;}

