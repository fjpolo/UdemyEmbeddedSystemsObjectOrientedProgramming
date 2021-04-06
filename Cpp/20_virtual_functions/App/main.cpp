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
	
	
	Led *led_p;
	led_p = new MedicalLed(10, 10, 500, 992, 2);
	
	printf("Voltage: %f\r\n", led_p->getVoltage());
	
	while(1){
	}
}


