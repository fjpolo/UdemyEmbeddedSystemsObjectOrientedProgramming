#include <stdint.h>
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
	UART_BaudrateType baudrate = _115200;
	UART_CommType commtype = RX_AND_TX;
	
	LIB_UART_Init(commtype, baudrate);
	
	while(1){
		LIB_UART_USART6_Write('Y');
		LIB_UART_USART6_Write('e');
		LIB_UART_USART6_Write('s');
		LIB_UART_USART6_Write('\n');
	}
	
}	





