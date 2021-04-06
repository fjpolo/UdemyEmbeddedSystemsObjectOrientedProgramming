#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uartBSP.h"
#include "gpio.h"
#include "stm32f4xx.h"                  // Device header


/*
*	Defines
*/
#define RED_LED_PORT					GPIOI
#define RED_LED_PIN						GPIO_PIN_7
#define GREEN_LED_PORT				GPIOB
#define GREEN_LED_PIN					GPIO_PIN_7
#define YELLOW_LED_PORT				GPIOG
#define YELLOW_LED_PIN				GPIO_PIN_11

/*LedColor_Type*/
#ifndef LedColor_Type
typedef  enum { 
	RED		= 0,
	GREEN,
	YELLOW
}LedColor_Type;
#endif // LedColor_Type

/*LedState_Type*/
#ifndef LedState_Type
typedef enum{
 OFF =0,
 ON = 1
}LedState_Type;
#endif // LedState_Type

/*Led's attributes*/
/*Led_Type*/
class Led{
	/*Attributes*/
	private:
		LedColor_Type color;
		LedState_Type state;
	/*Methods*/
	public:
		Led(LedColor_Type _color, LedState_Type _state);
		void setState(LedState_Type _state);
		LedState_Type getState()const;
};




#endif
