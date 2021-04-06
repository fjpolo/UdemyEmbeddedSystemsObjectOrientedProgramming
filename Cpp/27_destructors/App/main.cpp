#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
//#include "led.h"

class Led{
	public:
		int * default_pattern;
		Led(){
			printf("LED created\r\n");
			default_pattern = new int[20];
		}
		~Led(){
			printf("LED destroyed\r\n");
			delete[] default_pattern;
		}
};



/**
* main
*/
int main(void){
	USART6_Init();
	
//	Led myLed;
	Led *myLed_p;
	myLed_p = new Led;
	printf("Shutdown...\r\n");
	delete[] myLed_p;

}


