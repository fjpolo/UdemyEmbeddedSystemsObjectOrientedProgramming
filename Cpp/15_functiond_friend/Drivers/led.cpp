#include "led.h"

/**
* Led Class
*/

/*Constructor*/
Led::Led(){
	this->diameter = 3;
	this->voltage = 3.3;
	this->current = 200;
}
Led::Led(int diameter, float voltage, float current){
	setDiameter(diameter);
	setVoltage(voltage);
	setCurrent(current);
}
/*Accessors*/
int Led::getDiameter(){
	return this->diameter;
}
float Led::getVoltage(){
	return this->voltage;
}
float Led::getCurrent(){
	return this->current;
}
/*Mutators*/
void Led::setDiameter(int diameter){
	if(diameter > 0){
		this->diameter = diameter;
	}
	else this->diameter = 0;
}
void Led::setVoltage(float voltage){
	this->voltage = voltage;
}
void Led::setCurrent(float current){
	this->current = current;
}
/*Facilitators*/
float Led::power(){
	return (this->voltage*this->current);
}
/*Inspectors*/
int Led::isOn(){
	
}
/*Destructor*/
Led::~Led(){
	printf("\r\nObject destroyed!\r\n\r\n");
}



void printLedAttributes(Led led){
	printf("Led Diameter: %d\r\n", led.diameter);
	printf("Led Voltage: %f\r\n", led.voltage);
	printf("Led Current: %f\r\n", led.current);
}





