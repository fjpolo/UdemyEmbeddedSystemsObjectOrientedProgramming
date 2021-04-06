#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
//#include "led.h"

class Led{
	public:
		Led(){
			printf("LED created\r\n");
		}
		virtual ~Led(){
			printf("LED destroyed\r\n");
		}
};


class PowerLed:public Led{
public:
	PowerLed(){
		printf("PowerLED created\r\n");
	}
	~PowerLed(){
		printf("PowerLED destroyed\r\n");
	}
};

/**
* main
*/
int main(void){
	USART6_Init();

	Led *pLed_p;
	pLed_p	= new PowerLed;
	delete[] pLed_p;

}


