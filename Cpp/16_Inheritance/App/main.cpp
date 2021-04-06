#include "mcal_reg.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
#include "led.h"

struct UniqueLed{
	int diameter;
	float voltage;
	float current;
	/**/
	float power(){
	return (this->voltage*this->current);
}
};

int main(void){
	MedicalLed MedicalLed(5, 3.3, 200, 994);
	
	/**/
	printf("Diameter: %d\r\n", MedicalLed.getDiameter());
	printf("Voltage: %f\r\n", MedicalLed.getVoltage());
	printf("Current: %f\r\n", MedicalLed.getCurrent());
	printf("Wavelength: %f\r\n", MedicalLed.getWavelength());
	printf("M Factor: %f\r\n", MedicalLed.mFactor());
	
	while(1){
	}
}


