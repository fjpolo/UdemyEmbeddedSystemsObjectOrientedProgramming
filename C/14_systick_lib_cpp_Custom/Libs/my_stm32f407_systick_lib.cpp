#include "my_stm32f407_systick_lib.h"

SYSTICK::SYSTICK(){}
	
void SYSTICK::DelayS(uint32_t sec){
	int i;
	/*Configure SysTick*/
	SysTick->LOAD =  16000000 -1;
	SysTick->VAL =0; /*clear current value register*/
	SysTick->CTRL = 5; /*Enable systick, no interrupt*/
	
	for(i=0;i<sec;i++){	
		/*Wait until the COUNTFLAG is set*/
	  while((SysTick->CTRL &0x10000)== 0){}
			
	}	
	SysTick->CTRL =0;  /*Stop the timer (En =0)*/
}

void SYSTICK::DelayMs(uint32_t milli){
	int i;	
	/*Configure SysTick*/
	SysTick->LOAD =  16000 -1;
	SysTick->VAL =0; /*clear current value register*/
	SysTick->CTRL = 5; /*Enable systick, no interrupt*/
		for(i=0;i<milli;i++){
		/*Wait until the COUNTFLAG is set*/
	  while((SysTick->CTRL &0x10000)== 0){}		
	}
	SysTick->CTRL =0;  /*Stop the timer (En =0)*/
}