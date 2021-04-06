#ifndef  __UARTBSP_H
#define  __UARTBSP_H


#include "stm32f4xx.h"                  // Device header
#include <stdio.h>

/**
* Configurations
*/
#define			CR1_CNF1_RX					(0x0004U)			// Enable Rx, 8 bit data
#define			CR1_CNF1_TX					(0x0008U)			// Enable Tx, 8 bit data
#define 		BRR_CNF1_9600				(0x0683U)			// 9600 baud
#define 		BRR_CNF1_115200			(0x008BU)			// 9600 baud
#define			CR1_CNF1						(0x0008U)			// Enable Tx, 8 bit data
#define			CR2_CNF1						(0x0000U)			// 1 stop bit
#define			CR3_CNF1						(0x0000U)			// No flow-control
#define 		UART6_CR1_ENABLE		(0x2000U)			// Enable UART
#define 		UART6_CR1_DISABLE		(0x0000U)			// Disable UART


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


void USART2_Init(void);
void USART6_Init(void);
void test_setup(void);


#endif	// __UARTBSP_H
