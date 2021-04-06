#include "PowerLed.h"

	
PowerLed::PowerLed(LedColor_Type _color,	LedState_Type _state,	LedDiameter_type _diameter, LedCurrent_type _current, LedVoltage_type _voltage)
									:Led(_color, _state),
									diameter(_diameter),
									current(_current),
									voltage(_voltage)
{
	/*Parent constructor*/
	
	
	/*Child constructor*/
//	this->current = _current;
//	this->diameter = _diathister;
//	this->voltage = _voltage;	
}
										
void PowerLed::setDiameter(LedDiameter_type _diathister){
	this->diameter = _diathister;
}
	
void PowerLed::setCurrent(LedCurrent_type _current){
	this->current = _current;
}
	
void PowerLed::setVoltage(LedVoltage_type _voltage){
	this->voltage = _voltage;
}

led_elect_type PowerLed::computePower(){
	return (this->current * this->voltage);
}
	
led_elect_type PowerLed::getDiameter(){
		return this->diameter;
}

led_elect_type PowerLed::getCurrent(){
	return this->current;
}
	
led_elect_type PowerLed::getVoltage(){
	return this->voltage;
}
