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
	Led PoweLed;
	
	/**/
	printLedAttributes(PoweLed);
	
	while(1){
	}
}


