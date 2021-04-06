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
	GPIO_InitTypeDef myGPIOInitStructRedLed;
	GPIO_InitTypeDef myGPIOInitStructGreenLed;
	GPIO_InitTypeDef myGPIOInitStructYellowLed;


	
	/*RED*/
////	myGPIOInitStructRedLed.Mode = GPIO_MODE_OUTPUT_PP;
////	myGPIOInitStructRedLed.Pin = RED_LED_PIN;
////	myGPIOInitStructRedLed.Pull = GPIO_NOPULL;
//////		myGPIOInitStructRedLed.Alternate = ;
	
	
	myGPIOInitStructRedLed = __gpio_pin_params(RED_LED_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
	myGPIOInitStructGreenLed = __gpio_pin_params(GREEN_LED_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
	myGPIOInitStructYellowLed = __gpio_pin_params(YELLOW_LED_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);

	Gpio MyOutput0(PORTI, RED_LED_PORT, &myGPIOInitStructRedLed);
	Gpio MyOutput1(PORTB, GREEN_LED_PORT, &myGPIOInitStructGreenLed);
	Gpio MyOutput2(PORTG, YELLOW_LED_PORT, &myGPIOInitStructYellowLed);
	
	MyOutput2.TogglePin(GPIOG, YELLOW_LED_PIN);

	while(1){
		for(int i=0;i<1000000;i++);
		MyOutput0.TogglePin(GPIOI, RED_LED_PIN);
		MyOutput1.TogglePin(GPIOB, GREEN_LED_PIN);
		MyOutput2.TogglePin(GPIOG, YELLOW_LED_PIN);
	}
	
}	





