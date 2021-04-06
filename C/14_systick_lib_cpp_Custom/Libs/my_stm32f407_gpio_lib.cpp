#include "my_stm32f407_gpio_lib.h"

/**
* Defines
*/
#define GPIO_NUMBER				(16U)
#define GPIO_MODER_MODE0	(0x3U<<0)
#define GPIO_MODE					(0x03U)
#define GPIO_PUPDR_PUPDR0	(0x3U<<0)
#define	GPIO_OSPEEDER_OSPEEDR0			0x3U<<0
#define	GPIO_OTYPER_OT0							0x1U<<0
#define GPIO_OUTPUT_TYPE						0x00010U

/**
* Functions
*/
Gpio::Gpio(PORT_NameType _GPIO_portName, GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
	
	switch(_GPIO_portName){
		case PORTA:
		{
			__LIB_RCC_GPIOA_CLK_ENABLE();
			break;
		}
		case PORTB:
		{
			__LIB_RCC_GPIOB_CLK_ENABLE();
			break;
		}
		case PORTC:
		{
			__LIB_RCC_GPIOC_CLK_ENABLE();
			break;
		}
		case PORTD:
		{
			__LIB_RCC_GPIOD_CLK_ENABLE();
			break;
		}
		case PORTE:
		{
			__LIB_RCC_GPIOE_CLK_ENABLE();
			break;
		}
		case PORTF:
		{
			__LIB_RCC_GPIOF_CLK_ENABLE();
			break;
		}
		case PORTG:
		{
			__LIB_RCC_GPIOG_CLK_ENABLE();
			break;
		}
		case PORTH:
		{
			__LIB_RCC_GPIOH_CLK_ENABLE();
			break;
		}
		case PORTI:
		{
			__LIB_RCC_GPIOI_CLK_ENABLE();
			break;
		}
		default:
		{
			break;
		}
	} // END switch
	
	/**/
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
			/*Alternate function selection*/
			if( (GPIO_Init->Mode == GPIO_MODE_AF_PP) ||(GPIO_Init->Mode == GPIO_MODE_AF_OD) ){
				temp = GPIOx->AFL[position>>3U];
				temp &= ~(0xFU<<((uint32_t)(position&0x07U) * 4U));
				temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & 0x07U) * 4U));
				GPIOx->AFL[position>>3] = temp;
			}
				/* Configure IO Direction mode (Input, Output) */
				temp = GPIOx->MODER;
				temp &= ~(GPIO_MODER_MODE0 << (position * 2U));
				temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U));
				GPIOx->MODER = temp;
			
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
				
				/* Activate the Pull-up or Pull down resistor for the current IO */
				temp = GPIOx->PUPDR;
				temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
				temp |= ((GPIO_Init->Pull) << (position * 2U));
				GPIOx->PUPDR = temp;
		} // END if    
	} // END for
} // END LIB_GPIO_Init
	
GPIO_PinState Gpio::PinState(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	GPIO_PinState BitStatus;
	
	/*Read*/
	if( (GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET){
		BitStatus = GPIO_PIN_SET;
	} // END if
	else BitStatus = GPIO_PIN_RESET;
	
	/*Return*/
	return BitStatus;
} // END LIB_GPIO_ReadPin
	
void Gpio::WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
	/**/
	if( (PinState) != GPIO_PIN_RESET ){
		GPIOx->BSRR = GPIO_Pin;
	} // END if
	else{
		GPIOx->BSRR = (uint32_t)GPIO_Pin<<16U;
	} // END else
} // END LIB_GPIO_WritePin

void Gpio::TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	/*Toggle*/
	GPIOx->ODR ^= GPIO_Pin;
} // END LIB_GPIO_TogglePin
void Gpio::__LIB_RCC_GPIOA_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOA_EN;}
void Gpio::__LIB_RCC_GPIOB_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOB_EN;}
void Gpio::__LIB_RCC_GPIOC_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOC_EN;}
void Gpio::__LIB_RCC_GPIOD_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOD_EN;}
void Gpio::__LIB_RCC_GPIOE_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOE_EN;}
void Gpio::__LIB_RCC_GPIOF_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOF_EN;}
void Gpio::__LIB_RCC_GPIOG_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOG_EN;}
void Gpio::__LIB_RCC_GPIOH_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOH_EN;}
void Gpio::__LIB_RCC_GPIOI_CLK_ENABLE()const{RCC->AHB1ENR |= GPIOI_EN;}

/**
* 	Functions
*/
GPIO_InitTypeDef __gpio_pin_params(PinDataType _Pin, PinDataType _Mode, PinDataType _Pull){
	GPIO_InitTypeDef pinGPIOInitStruct;
	pinGPIOInitStruct.Mode = _Mode;
	pinGPIOInitStruct.Pin = _Pin;
	pinGPIOInitStruct.Pull = _Pull;
	return pinGPIOInitStruct;
}