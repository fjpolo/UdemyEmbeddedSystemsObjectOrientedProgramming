#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"

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