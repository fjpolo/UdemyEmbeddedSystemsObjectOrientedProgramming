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
	/*Virtual pointer*/
	struct LedVtable const *vptr;
	/*Attributes*/
	LedColor_Type color;  /*Color of Led*/
	LedState_Type state;  /*State of Led*/
}Led_Type;
#endif // Led_Type

/*Led Virtual table*/
struct LedVtable{
	void(*run_diagnostics)(Led_Type const * const me);
	uint32_t(*compute_efficiency)(Led_Type const * const me);
};

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

/*Polymorphism method 1*/
static inline void Led_run_diagnostics_vcall(Led_Type const * const me){(*me->vptr->run_diagnostics)(me);}
static uint32_t Led_compute_efficiency_vcall(Led_Type const * const me){return (*me->vptr->compute_efficiency)(me);}

/*Polymorphism method 2*/
#define LED_RUN_DIAG_VCALL(me)				((*(me)->vptr->run_diagnostics)(me))
#define LED_GET_EFF_VCALL(me)					((*(me)->vptr->compute_efficiency)(me))

/*Polymorphism*/
void runSystemDiagnostics(Led_Type const * led_modules[]);
void computeLedEffs(Led_Type const * led_modules[]);

#endif
