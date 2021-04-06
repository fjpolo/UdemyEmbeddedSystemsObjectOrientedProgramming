#include "mcal_reg.h"
#include "uartBSP.h"
#include <iostream>	// adds 26k flash!!!!!!
//#include <stdio.h>

int main(void){
	USART6_Init();
	int size, itr;
	int *all_scores;
	
	/**/
	std::cout<<"How many scores would you like to enter:\r\n";
	std::cin>>size;
		
	/**/
	all_scores = new int(size);
	if(all_scores == NULL){
		std::cout<<"Error: Not enough memory!!\r\n";
	}
	else{
		for(itr=0;itr<size;itr++){
			std::cout<<"Enter score:\r\n";
			std::cin>>all_scores[itr];
		}
		std::cout<<"You entered these scores:\r\n";
		for(itr=0;itr<size;itr++){
			std::cout<<all_scores[itr]<<", ";
			std::cout<<"\r\n";
		}
		delete[] all_scores;
	}
	
	/**/
	while(1){
	}
}
