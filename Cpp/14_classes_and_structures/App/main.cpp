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
	UniqueLed RedLed, GreenLed;
	UniqueLed *GreenLed_p;
	
	/*Initialize GreenLed_p*/
	GreenLed_p = &GreenLed;
	GreenLed_p->diameter = 5;
	GreenLed_p->current = 200;
	GreenLed_p->voltage = 3.3;
	
	/**/
	printf("GreenLed Lower: %f\r\n", GreenLed_p->power());
		
	while(1){
	}
}


