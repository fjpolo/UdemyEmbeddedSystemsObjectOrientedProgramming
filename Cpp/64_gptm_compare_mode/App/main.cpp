#include "uart.h"
#include "stdio.h"
#include "systick.h"
#include "tim2.h"

int main(void){		
	int SysTickFlag;

	
	/*Init USART6*/
	uart6_init();
////	/*Init compare timer2*/
////	tim2_ch1_compare_mode_init();
//	Timer *tim2 = new (Timer::TimerModules::Module2) Timer;
////	tim2->Init_1Hz();
//	tim2->InitCh1CompareMode();
	/*Create an object*/
	Timer &tim3 = * new (Timer::TimerModules::Module3) Timer;
	tim3.InitCh1CompareMode();
	
											 
	
	
	
	
	/*Superloop*/
	while(true){
		/*Wait for timeout*/
		tim3.WaitForTimeout();
		
	}
}
