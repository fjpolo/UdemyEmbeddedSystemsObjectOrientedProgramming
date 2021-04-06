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
		systick_delayMs(500);
		printf("Systick Timeout!!\r\n");
	}
}
