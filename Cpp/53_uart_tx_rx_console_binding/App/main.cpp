//#include "mcal_reg.h"
#include "uart.h"
//#include <iostream>
//#include "mcal_reg.h"
#include "stdio.h"

int main(void){
	static char msgChar;									 
											 
	/*Init USART6*/
	uart6_init();
	
	/*Superloop*/
	while(true){
		//std::cout<<"Hello world"<<std::endl;
		printf("Hello world\r\n");

	}	
}
