#include "PowerLed.h"
PowerLed::PowerLed(
									 LedColor_Type   _color,
									 LedState_Type	_state,
									 LedDiamter_Type  _diameter,
									 LedCurrent_Type   _current,
									 LedVoltage_Type  _voltage)
	 :Led(_color,_state),
		diameter(_diameter),
    current(_current),
    voltage(_voltage)
{
										 
}
									 
void PowerLed::PowerLed_setCurrent(LedCurrent_Type  _current ){
	
 this->current = _current;
}

void PowerLed::PowerLed_setDiameter( LedDiamter_Type _diameter){
	
	 this->diameter = _diameter;
}

void PowerLed::PowerLed_setVoltage( LedVoltage_Type _voltage){

  this->voltage = _voltage;
}


led_elec_type PowerLed::PowerLed_computePower(){

  return(this->current * this->voltage);
}


led_elec_type PowerLed::PowerLed_getCurrent(){

   return this->current;
}

led_elec_type PowerLed::PowerLed_getDiameter(){

  return this->diameter;
}


led_elec_type PowerLed::PowerLed_getVoltage(){

 return this->voltage;
}
