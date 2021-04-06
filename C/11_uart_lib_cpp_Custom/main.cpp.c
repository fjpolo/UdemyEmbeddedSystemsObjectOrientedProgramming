#include "my_stm32f407_uart_lib.h"

/**
 * LEDS
 */
#define RED_LED_PORT					GPIOI
#define RED_LED_PIN						GPIO_PIN_7
#define GREEN_LED_PORT				GPIOB
#define GREEN_LED_PIN					GPIO_PIN_7
#define YELLOW_LED_PORT				GPIOG
#define YELLOW_LED_PIN				GPIO_PIN_11



int main(void){
	UARTcomm UART6Comm(RX_AND_TX, _115200);
	
	while(1){
		UART6Comm.Write('x');
		//printf("BR: %d\n", UART6Comm.getBaudrate());
		//printf("CT: %d\n", UART6Comm.getCommtype());
	}
	
}	





