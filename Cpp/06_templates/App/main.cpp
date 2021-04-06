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

int main(void){
	USART6_Init();
	
	int num1 = 45;
	int num2 = 67;
	int ans;
	float fnum1 = 78.9;
	float fnum2 = 54.78;
	float fans1, fans2;
	
//	ans = int_adder(num1, num2);
//	fans = float_adder(fnum1, fnum2);
	ans = adder(num1, num2);
	fans1 = adder(fnum1, fnum2);
//	fans2 = adder(num1, fnum2);
	
	printf("%d + %d = %d\r\n", num1, num2, ans);
	printf("%f + %f = %f\r\n", fnum1, fnum2, fans1);
	printf("%d + %f = %f\r\n", num1, fnum2, fans2);
	
	/**/
	while(1){
	}
}
