#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include "stm32f4xx.h"                  // Device header

#define	LED_PORT 		GPIOB

#define	LED_PORT_CLOCK  (1U<<1)

#define LED_RED_PIN			(1U<<14)
#define LED_GREEN_PIN		(1U<<12)
#define	LED_BLUE_PIN		(1U<<15)
#define LED_YELLOW_PIN	(1U<<13)

#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)



typedef  enum {
  
	RED		= 0,
	GREEN,
	YELLOW,
	BLUE

}LedColor_Type;


typedef enum{
 OFF =0,
 ON = 1
}LedState_Type;


/*Led's attributes*/

typedef struct{
	
 LedColor_Type color;  /*Color of Led*/
 LedState_Type state;  /*State of Led*/
	
}Led_Type;


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);
#endif