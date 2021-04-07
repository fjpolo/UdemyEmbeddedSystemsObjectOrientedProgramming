#include "uart.h"
#include "stdio.h"
#include "systick.h"
#include "tim2.h"
#include "tim3.h"

int main(void){		
	int SysTickFlag;

	
	/*Init USART6*/
	uart6_init();
	/*Init compare timer2*/
	tim2_ch1_compare_mode_init();
	
	
											 
	
	
	
	
	/*Superloop*/
	while(true){

		
	}
}
