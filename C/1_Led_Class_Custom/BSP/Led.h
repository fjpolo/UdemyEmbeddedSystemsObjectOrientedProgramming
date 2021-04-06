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
#ifndef Led_Type
typedef struct{
 LedColor_Type color;  /*Color of Led*/
 LedState_Type state;  /*State of Led*/
}Led_Type;
#endif // Led_Type

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);
#endif
