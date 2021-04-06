#ifndef _POWERLED_H
#define _POWERLED_H

#include "Led.h"

/*led_elect_type*/
#ifndef led_elect_type
typedef uint8_t led_elect_type;
#endif // led_elect_type

/*led_dim_type*/
#ifndef led_dim_type
typedef uint8_t led_dim_type;
#endif // led_dim_type

/*LedCurrent_type*/
#ifndef LedCurrent_type
typedef enum{
	CURR_LOW = 10,		// mA
	CURR_NORMAL = 20,
	CURR_HIGH = 35,
	CURR_VErY_HIGH = 60
}LedCurrent_type;
#endif // LedCurrent_type

/*LedDiameter_type*/
#ifndef LedDiameter_type
typedef enum{
	DIAM_2MM = 2,		// 2mm
	DIAM_5MM = 5,
	DIAM_7MM = 7
}LedDiameter_type;
#endif // LedDiameter_type
	
/*LedVoltage_type*/
#ifndef LedVoltage_type
typedef enum{
	VOLT_LOW = 3,	// 3V
	VOLT_NORM = 5,
	VOLT_HIGH = 9
}LedVoltage_type;
#endif // LedVoltage_type

/*PowerLed_type*/
#ifndef PowerLed_type
typedef struct{
	Led_Type super;
	LedDiameter_type diameter;
	LedCurrent_type current;
	LedVoltage_type voltage;
}PowerLed_type;
#endif // PowerLed_type

/*
*
*/
void PowerLed_ctor( PowerLed_type * const me, 
										LedColor_Type _color,
										LedState_Type _state,
										LedDiameter_type _diameter,
										LedCurrent_type _current,
										LedVoltage_type _voltage
									);
void PowerLed_setDiameter(PowerLed_type * const me, LedDiameter_type _diameter);
void PowerLed_setCurrent(PowerLed_type * const me, LedCurrent_type _current);
void PowerLed_setVoltage(PowerLed_type * const me, LedVoltage_type _voltage);
led_elect_type PowerLed_computePower(PowerLed_type * const me);
led_elect_type PowerLed_getDiameter(PowerLed_type * const me);
led_elect_type PowerLed_getCurrent(PowerLed_type * const me);
led_elect_type PowerLed_getVoltage(PowerLed_type * const me);
/*Virtual functions*/
void PowerLed_runDiagnostics(PowerLed_type const * const me);
uint32_t PowerLed_computeEfficiency(PowerLed_type const * const me);

#endif // _POWERLED_H
