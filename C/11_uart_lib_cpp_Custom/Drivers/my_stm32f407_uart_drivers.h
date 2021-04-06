#ifndef __MY_STM32F407_UART_DRIVERS_H
#define __MY_STM32F407_UART_DRIVERS_H

#include "my_stm32f407_gpio_drivers.h"

#ifndef __IO
#define             __IO                    volatile
#endif // __IO

/**
 * 
 */
#define                         USART6_BASE              (APB2PERIPH_BASE + 0x1400U)						// 0x4001 1400

/**
 * 
 */
/*USART_TypeDef*/
#ifndef USART_TypeDef
typedef struct{
    __IO    uint32_t    SR;     //Status register
    __IO    uint32_t    DR;     // Data register    
    __IO    uint32_t    BRR;    // Baud rate register
    __IO    uint32_t    CR1;    // Control register 1
    __IO    uint32_t    CR2;    // Control register 2 
    __IO    uint32_t    CR3;    // Control register 3 
    __IO    uint32_t    GTPR;   //  Guard time and prescaler register  
}USART_TypeDef;
#endif // USART_TypeDef

/*USART6*/
#ifndef USART6
#define USART6  ((USART_TypeDef*)(USART6_BASE))
# endif // USART6

#endif // __MY_STM32F407_UART_DRIVERS_H

