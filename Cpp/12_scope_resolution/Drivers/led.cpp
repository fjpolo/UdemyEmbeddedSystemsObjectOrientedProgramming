#include "led.h"

/**
* Led Class
*/

/*Constructor*/
Led::Led(){
	diameter = 3;
	voltage = 3.3;
	current = 200;
}
Led::Led(int d, float v, float i){
	setDiameter(d);
	setVoltage(v);
	setCurrent(i);
}
/*Accessors*/
int Led::getDiameter(){
	return diameter;
}
float Led::getVoltage(){
	return voltage;
}
float Led::getCurrent(){
	return current;
}
/*Mutators*/
void Led::setDiameter(int d){
	if(d > 0){
		diameter = d;
	}
	else diameter = 0;
}
void Led::setVoltage(float v){
	voltage = v;
}
void Led::setCurrent(float i){
	current = i;
}
/*Facilitators*/
float Led::power(){
	return (voltage*current);
}
/*Inspectors*/
int Led::isOn(){
	
}
/*Destructor*/
Led::~Led(){
	
}

