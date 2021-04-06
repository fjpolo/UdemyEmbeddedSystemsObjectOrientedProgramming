#include  "my_stm32f4_uart_driver.h"


void USART2_write(int ch);


int main(void){

		RCC->AHB1ENR |=1;  //Enable GPIOA clock
		RCC->APB1ENR |= 0x20000; //Enable USART2 clock
	
	  GPIOA->AFR[0] |=0x0700; //alt7 for USART2
		GPIOA->MODER  |=  0x0020; //Enable alternate function
	
	  USART2->BRR = 0x0683; //9600 baud @ 16 Mhz
	  USART2->CR1 = 0x0008; //Enable Tx, 8-bit data
		USART2->CR2 = 0x0000; //1 stop bit
	  USART2->CR3 =  0x0000; //no flow control
	  USART2->CR1 |= 0x2000;
	


	while(1){
		
		USART2_write('Y');
		USART2_write('e');
		USART2_write('s');
		USART2_write('\r');
		USART2_write('\n');


	}
   
}


void USART2_write(int ch){

	while(!(USART2->SR & 0x0080)){} //Wait for transfer buffer to be empty
   USART2->DR = (ch&0xFF);
}








