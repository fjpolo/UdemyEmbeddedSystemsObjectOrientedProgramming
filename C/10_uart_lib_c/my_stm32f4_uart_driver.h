#ifndef __MY_STM32F4_UART_DRIVER_H
#define __MY_STM32F4_UART_DRIVER_H

#include  "my_stm32f4_gpio_driver.h"


#define		__IO			volatile

#define APB1PERIPH_BASE			(PERIPH_BASE +  0x00000000U)
#define USART2_BASE			    (APB1PERIPH_BASE + 0x4400U)


typedef struct
{
	__IO uint32_t SR;    /*USART Status Register*/
	__IO uint32_t DR;	 	/*USART Data Register*/
	__IO uint32_t BRR;   /*USART Buad rate register*/
	__IO uint32_t CR1;    /*USART Control Register 1*/
	__IO uint32_t CR2;    /*USART Control Register 2*/
	__IO uint32_t CR3;    /*USART Control Register 3*/

}USART_TypeDef;

#define		USART2				((USART_TypeDef *)USART2_BASE)

#endif