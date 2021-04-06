#include "mcal_reg.h"
#include "uartBSP.h"
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
	USART6_Init();
	Led *mled_p;	
	Led *dled_p;
	
	mled_p = new MedicalLed();
	dled_p = new DisplayLed();
	
	mled_p->ledState();
	dled_p->ledState();
	
	while(1){
	}
}


