#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>

#define SCORE_NUM	5

int * score_setter(){
	int * ptr = new int[SCORE_NUM];
	if(ptr == NULL){
		printf("Error: not enough memory!\r\n");
	}
	else{
		for(int i=0;i<SCORE_NUM;i++){
		ptr[i] = 0;
		}
	}
	return ptr;
}

	int main(void){
	USART6_Init();
	int *grade4_scores = score_setter();
	for(int i=0;i<SCORE_NUM;i++){
		printf("Enter score:");
		scanf("%d", &grade4_scores[i]);
	}
	printf("The scores for grade4 are");
	for(int i=0;i<SCORE_NUM;i++){
		printf("%d, ", grade4_scores[i]);
	}
	
	delete[] grade4_scores;
	
	/**/
	while(1){
	}
}
