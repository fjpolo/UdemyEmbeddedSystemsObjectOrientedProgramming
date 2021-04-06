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
	MedicalLed MedicalLed(5, 3.3, 200, 994, 4);
	
	/**/
//	printf("Nr of pins: %d\r\n", MedicalLed.nrOfPins);
	MedicalLed.getLedType();
	
	while(1){
	}
}


