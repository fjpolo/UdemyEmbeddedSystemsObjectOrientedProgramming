#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>

//int int_adder(int a, int b){
//	return a+b;
//}

//float float_adder(float a, float b){
//	return a+b;
//}

template<class T>
	T adder(T a, T b){
		return a+b;
	}

int add_tripe(int a, int b, int c=15){
		return (a+b+c);
}

	int main(void){
	USART6_Init();
		
		int a = 20;
		int b = 30;
		int c = 40;
		
	printf("%d + %d + %d = %d\r\n", a, b, c, add_tripe(a,b,c));
	printf("%d + %d + default = %d\r\n", a, b, add_tripe(a,b));

	
	/**/
	while(1){
	}
}
