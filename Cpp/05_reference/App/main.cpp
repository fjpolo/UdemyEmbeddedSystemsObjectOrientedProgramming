#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>

int main(void){
	USART6_Init();

	/**/
	int num = 234;
	int &ref_alias = num;
	int norm_alias = num;
	
	printf("num: %d\r\n", num);
	printf("ref_alias: %d\r\n", ref_alias);
	printf("norm_alias: %d\r\n", norm_alias);	
	printf("\r\n");
	
	ref_alias++;
	norm_alias++;
	
	printf("num: %d\r\n", num);
	printf("ref_alias: %d\r\n", ref_alias);
	printf("norm_alias: %d\r\n", norm_alias);
	
	/**/
	while(1){
	}
}
