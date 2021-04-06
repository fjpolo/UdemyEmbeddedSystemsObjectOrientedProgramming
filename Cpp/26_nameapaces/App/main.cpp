#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
//#include "led.h"

namespace Led{
	/*LED diagnostics*/
	void diagnosticsReport(){
		printf("LED Module working!\r\n");
	}
}

namespace Motor{
	/*Motor diagnosctics*/
	void diagnosticsReport(){
		printf("Motor Module working!\r\n");
	}
}



/**
* main
*/
using namespace Led;
int main(void){
	USART6_Init();
	
	/*LED*/
	diagnosticsReport();
	/*Motor*/
	Motor::diagnosticsReport();
	
	while(1){
	}
}


