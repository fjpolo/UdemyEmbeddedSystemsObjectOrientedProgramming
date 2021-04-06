#include <stdint.h>
#include "my_stm32f407_gpio_lib.h"

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
	static GPIO_InitTypeDef myGPIOInitStructRedLed;
//	static GPIO_TypeDef	GPIOTypeStructRedLed;
//	static GPIO_InitTypeDef myGPIOInitStructGreenLed;
//	static GPIO_TypeDef	GPIOTypeStructGreenLed;
//	static GPIO_InitTypeDef myGPIOInitStructYellowLed;
//	static GPIO_TypeDef	GPIOTypeStructYellowLed;
	
	/*RED*/
	myGPIOInitStructRedLed.Mode = GPIO_MODE_OUTPUT_PP;
	myGPIOInitStructRedLed.Pin = GPIO_PIN_7;
	myGPIOInitStructRedLed.Pull = GPIO_NOPULL;
	
	/*Green*/
	
	/*Yellow*/
	
	/*Init*/
	__LIB_RCC_GPIOB_CLK_ENABLE();
	__LIB_RCC_GPIOG_CLK_ENABLE();
	__LIB_RCC_GPIOI_CLK_ENABLE();
	
	/**/
	LIB_GPIO_Init(RED_LED_PORT, &myGPIOInitStructRedLed);
	
	while(1){
		LIB_GPIO_TogglePin(RED_LED_PORT, RED_LED_PIN);
		for(int i=0;i<1000;i++);
	}
	
}	





