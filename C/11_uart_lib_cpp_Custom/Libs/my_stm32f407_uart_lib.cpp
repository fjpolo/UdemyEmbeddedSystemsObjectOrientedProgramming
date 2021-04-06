#include "my_stm32f407_uart_lib.h"

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


UARTcomm::UARTcomm(UART_CommType commtype, UART_BaudrateType baudrate){
	this->baudrate = baudrate;
	this->commtype = commtype;
	
	/*Enable port clock*/
	RCC->AHB1ENR |= 0x04;			// Enable GPIOC Clock - PC6 -> USART6_TX
	RCC->AHB1ENR |= 0x40;			// Enable GPIOG Clock - PG8 -> USART6_RX
	RCC->APB2ENR |= 0x20;			// Enable UART6 Clock
	
	/*Disable UART*/
	USART6->CR1 = UART6_CR1_DISABLE;	
	
	/*Enable Alternate functions*/
	if(commtype == TX_ONLY){
		GPIOC->AFR[0] |= 0x7000000; // Write AF7 (0b0111) to AFRL6[3:0] (PC6)
		GPIOC->MODER |= 0x2000;
		USART6->CR1 = CR1_CNF1_TX;		// Enable Tx, 8 bit data
	}
	else if(commtype == RX_ONLY){
		GPIOG->AFR[1] |= 0x07;			// Write AF7 (0b0111) to AFRL8[3:0] (PG8)
		GPIOG->MODER |= 0x20000;
		USART6->CR1 = CR1_CNF1_RX;		// Enable Rx, 8 bit data
	}
	else if(commtype == RX_AND_TX){
		GPIOC->AFR[0] |= 0x7000000; // Write AF7 (0b0111) to AFRL6[3:0] (PC6)
		GPIOG->AFR[1] |= 0x07;			// Write AF7 (0b0111) to AFRL8[3:0] (PG8)
		GPIOC->MODER |= 0x20000 | 0x2000;
		USART6->CR1 = CR1_CNF1_TX | CR1_CNF1_TX;		// Enable Tx, 8 bit data
	}
	
	/*Baudrate*/
	switch(baudrate){
		case _9600:
		{
			USART6->BRR = BRR_CNF1_9600;		// 9600 baud
			break;
		}
		case _115200:
		{
			USART6->BRR = BRR_CNF1_115200;		// 9600 baud
			break;
		}
		default:
		{
			break;
		}
	}
	
	/*Control Register*/ 
	USART6->CR2 = CR2_CNF1;		// 1 stop bit
	USART6->CR3 = CR3_CNF1;		// No flow-control
	
	/*Enable UART*/
	USART6->CR1 |= UART6_CR1_ENABLE;	// 
}

void UARTcomm::Write(int ch){
	while( !(USART6->SR & 0x0080) );
	USART6->DR = (ch & 0xFF);
}

char UARTcomm::Read()const{
	while( !(USART6->SR & 0x0020) );
	return USART6->DR;
}

UART_BaudrateType UARTcomm::getBaudrate()const{
	return this->baudrate;
}
UART_CommType UARTcomm::getCommtype()const{
	return this->commtype;
}