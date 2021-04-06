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
	
	
	
	MedicalLed *mled_p;
	mled_p = new MedicalLed(5, 3.3, 200, 992, 4);
	
	printf("Voltage: %f\r\n", mled_p->getVoltage());
	
	while(1){
	}
}


