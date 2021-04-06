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


SYSTICK mySisTick;
GPIO_InitTypeDef myGPIOInitStructRedLed;
int main(void){
	myGPIOInitStructRedLed = __gpio_pin_params(RED_LED_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
	Gpio MyOutput0(PORTI, RED_LED_PORT, &myGPIOInitStructRedLed);	
	while(1){
	 mySisTick.DelayMs(500);
	 MyOutput0.TogglePin(GPIOI, RED_LED_PIN); 
	}
}






