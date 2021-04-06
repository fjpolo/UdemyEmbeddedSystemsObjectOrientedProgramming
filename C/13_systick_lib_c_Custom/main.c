#include <stdint.h>
#include "my_stm32f407_uart_lib.h"
#include "my_stm32f407_gpio_lib.h"
#include "my_stm32f407_systick_lib.h"

/**
 * LEDS
 */
#define RED_LED_PORT					GPIOI
#define RED_LED_PIN						GPIO_PIN_7
#define GREEN_LED_PORT				GPIOB
#define GREEN_LED_PIN					GPIO_PIN_7
#define YELLOW_LED_PORT				GPIOG
#define YELLOW_LED_PIN				GPIO_PIN_11


GPIO_InitTypeDef myGPIO_InitStruct;

int main(void){

	__LIB_RCC_GPIOI_CLK_ENABLE();
	
	myGPIO_InitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin  = RED_LED_PIN;
	myGPIO_InitStruct.Pull = GPIO_NOPULL;
	
	LIB_GPIO_Init(RED_LED_PORT,&myGPIO_InitStruct);
	
	while(1){
		
	 LIB_SYSTICK_DelayMs(500);
	 LIB_GPIO_TogglePin(RED_LED_PORT,RED_LED_PIN); 
	}
}






