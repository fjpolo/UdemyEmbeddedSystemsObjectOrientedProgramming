#include "uart.h"
#include "stdio.h"
#include "systick.h"

int main(void){		
	int SysTickFlag;

	
	/*Init USART6*/
	uart6_init();
	/*Init SysTick*/
	systick_init_1sec();
	
	
	/*Superloop*/
	while(true){
		SysTickFlag = systick_get_count_flag();
		if(SysTickFlag){
			printf("SysTick Timeout!!\r\n");			
		}
	}	
}
