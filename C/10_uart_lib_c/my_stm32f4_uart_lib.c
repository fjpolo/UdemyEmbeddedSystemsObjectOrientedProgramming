#include "my_stm32f4_uart_lib.h"

#define CR1_CNF1_RX         0x0004 //Enable Rx,8-bit data

#define BRR_CNF1_9600				0x0683 //9600 baud @ 16 Mhz
#define BRR_CNF1_115200     0x008b  //115200  baud @ 16 Mhz
#define CR1_CNF1_TX				  0x0008 //Enable Tx, 8-bit data
#define	CR2_CNF1	  				0x0000 //1 stop bit
#define	CR3_CNF1	  				0x0000  //no flow control
#define UART2_CR1_EN1				0x2000  //Enable UART
#define UART2_CR1_DIS				0x0000  //Disable UART



void LIB_UART_Init(UART_ComType comtype, UART_BaudrateType baudrate){

	RCC->AHB1ENR |=1;  //Enable GPIOA clock
  RCC->APB1ENR |= 0x20000; //Enable USART2 clock
	
	USART2->CR1 = UART2_CR1_DIS;
	
	switch(comtype){
		
		case TX_ONLY:
			
			GPIOA->MODER  |=  0x0020; //Enable alternate function at PA2
			GPIOA->AFR[0] |=0x0700; //alt7 for USART2
			USART2->CR1 = CR1_CNF1_TX; // Enable TX,  8-bit data
			
		  break;
		
		case RX_ONLY:
			
		  GPIOA->MODER  |= 0x0080;  //PA3 
		  GPIOA->AFR[0] |= 0x7000;  //alt7 for UART2
		  USART2->CR1 = CR1_CNF1_RX;
			break;
		
		case RX_AND_TX:
		  GPIOA->MODER  |= 0x0020 |0x0080;
		  GPIOA->AFR[0] |=0x0700 |0x7000;
		  USART2->CR1   |=CR1_CNF1_TX|CR1_CNF1_RX;
			
			break;
		
		default:
			break;
	
	}
	
	switch(baudrate){
	
		case _115200:
			USART2->BRR = BRR_CNF1_115200;
			break;
	  
		case _9600:
			USART2->BRR = BRR_CNF1_9600;
      break;
		
		default:
			break;
	
	}
	
	USART2->CR2  = CR2_CNF1;
	USART2->CR3  = CR3_CNF1;
	USART2->CR1 |= UART2_CR1_EN1;

}



char LIB_UART_Read(void){
  
	while(!(USART2->SR & 0x0020)){}//Wait till character arrives
	return USART2->DR;
	
}

void LIB_UART_Write(int ch){

	while(!(USART2->SR & 0x0080)){} // Wait until Tx buffer empty
	USART2->DR = (ch & 0xFF);
}

