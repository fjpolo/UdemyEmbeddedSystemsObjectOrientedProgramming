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
	
 struct LedVtable const *vptr; /*virtual pointer*/	
 LedColor_Type color;  /*Color of Led*/
 LedState_Type state;  /*State of Led*/
	
}Led_Type;


/*Led virtual table*/
struct LedVtable{

	void(*run_diagnostics)(Led_Type const * const me);
	 uint32_t (*compute_efficiency)(Led_Type const * const me);

};

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

/*Method 1*/
static inline void Led_runDiagnostics_vcall(Led_Type const * const me){
   
	(*me->vptr->run_diagnostics)(me);
}

static inline uint32_t Led_computeEffi_vcall(Led_Type const * const me){
  return (*me->vptr->compute_efficiency)(me);
}

/*Method 2*/

#define LED_RUN_DIAG_VCALL(me)		(*(me)->vptr->run_diagnostics)(me)
#define LED_GET_EFFI_VCALL(me)    (*(me)->vptr->compute_efficiency)(me)



void runSystemDiagnostics(Led_Type const *led_modules[]);
void computeLedEffs(Led_Type const * led_modules[]);

#endif