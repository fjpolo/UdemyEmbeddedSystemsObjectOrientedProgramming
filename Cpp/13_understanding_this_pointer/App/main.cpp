#include "mcal_reg.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
#include "led.h"

int main(void){
	Led RedLed, GreenLed(5, 3.3, 0.2);
	Led *GreenLed_p;
	
	/*Initialize GreenLed_p*/
	GreenLed_p = &GreenLed;
//	GreenLed_p->setDiameter(5);
//	GreenLed_p->setCurrent(0.8);
//	GreenLed_p->setVoltage(3.3);
	
	/**/
	printf("GreenLed Lower: %f\r\n", GreenLed_p->power());
		
	while(1){
	}
}


