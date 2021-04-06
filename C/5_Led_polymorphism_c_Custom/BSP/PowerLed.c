#include "PowerLed.h"

#ifdef __cplusplus
extern "C" {
#endif	//__cplusplus
	
void PowerLed_ctor( PowerLed_type * const me,	LedColor_Type _color,	LedState_Type _state,	LedDiameter_type _diameter, LedCurrent_type _current, LedVoltage_type _voltage){
	/*Virtual table*/
	static const struct LedVtable vtable={
		(void(*)(Led_Type const * const me))&PowerLed_runDiagnostics,
		(uint32_t(*)(Led_Type const * const me))&PowerLed_computeEfficiency
	};
	
	/*Parent constructor*/
	Led_ctor(&(me->super), _color, _state);
	me->super.vptr = &vtable;
	
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
	


/*Virtual functions*/
void PowerLed_runDiagnostics(PowerLed_type const * const me){
	/**/
	printf("Running power diagnosis\n");
	/**/
	for(int i=0;i<30;i++){
		printf(".\n");
	}
	/**/
	printf("Done!\n");
}
uint32_t PowerLed_computeEfficiency(PowerLed_type const * const me){
	const int8_t input = 120;
	const int8_t output = 8;
	int eff;

	/*Efficiency*/
	eff = ((input/output) * 100) - ((me->current)/2);
	printf("Efficiency = %d\n", eff);
}

#ifdef __cplusplus
}
#endif	//__cplusplus
