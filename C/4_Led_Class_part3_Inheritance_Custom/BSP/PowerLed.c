#include "PowerLed.h"

#ifdef __cplusplus
extern "C" {
#endif	//__cplusplus
	
void PowerLed_ctor( PowerLed_type * const me,	LedColor_Type _color,	LedState_Type _state,	LedDiameter_type _diameter, LedCurrent_type _current, LedVoltage_type _voltage){
	/*Parent constructor*/
	Led_ctor(&(me->super), _color, _state);
	
	/*Child constructor*/
	me->current = _current;
	me->diameter = _diameter;
	me->voltage = _voltage;	
}
										
void PowerLed_setDiameter(PowerLed_type * const me, LedDiameter_type _diameter){
	me->diameter = _diameter;
}
	
void PowerLed_setCurrent(PowerLed_type * const me, LedCurrent_type _current){
	me->current = _current;
}
	
void PowerLed_setVoltage(PowerLed_type * const me, LedVoltage_type _voltage){
	me->voltage = _voltage;
}

led_elect_type PowerLed_computePower(PowerLed_type * const me){
	return (me->current * me->voltage);
}
	
led_elect_type PowerLed_getDiameter(PowerLed_type * const me){
		return me->diameter;
}

led_elect_type PowerLed_getCurrent(PowerLed_type * const me){
	return me->current;
}
	
led_elect_type PowerLed_getVoltage(PowerLed_type * const me){
	return me->voltage;
}
	

#ifdef __cplusplus
}
#endif	//__cplusplus
