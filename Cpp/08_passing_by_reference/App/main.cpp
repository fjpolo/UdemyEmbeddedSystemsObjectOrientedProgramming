#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>


void swapper_value(int a,int b){
	int aux;
	aux = a;
	b=a;
	a=aux;
	
	printf("Value:");
	printf("a: %d, b: %d\r\n", a, b);
}

void swapper_reference(int &a,int &b){
	int aux;
	aux = a;
	b=a;
	a=aux;
	
	printf("Reference:");
	printf("a: %d, b: %d\r\n", a, b);
}

void swapper_pointer(int *a,int *b){
	int aux;
	aux = *a;
	*b=*a;
	*a=aux;
	
	printf("Reference:");
	printf("a: %d, b: %d\r\n", *a, *b);
}

	int main(void){
	USART6_Init();
	
	int num1=10;
	int num2=20;
	
	/*Passing by value*/
	printf("Before:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	swapper_value(num1, num2);
	printf("After:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	printf("\r\n");
		
	/*Passing by reference*/
	num1=10;
	num2=20;
	printf("Before:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	swapper_reference(num1, num2);
	printf("After:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	printf("\r\n");
	
	/*Passing by pointer*/
	num1=10;
	num2=20;
	printf("Before:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	swapper_pointer(&num1, &num2);
	printf("After:");
	printf("num1: %d, num2: %d\r\n", num1, num2);
	printf("\r\n");
	
	/**/
	while(1){
	}
}
