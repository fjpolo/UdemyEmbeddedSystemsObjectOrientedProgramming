#include "uart.h"
#include "stdio.h"
#include "systick.h"
#include "tim2.h"

int main(void){		
	int SysTickFlag;

	
	/*Init USART6*/
	uart6_init();
	/*Init SysTick*/
	systick_init_1sec();
	
	/*TIMER2*/
//	Timer *const Timer2 = reinterpret_cast(0xE000E010U);
//	Timer *const Timer2 = reinterpret_cast(mcal::reg::tim2_base);
//	Timer *const Timer2 = reinterpret_cast<Timer*>(0xE000E010U);
//	Timer *const Timer2 = reinterpret_cast<Timer*>(mcal::reg::tim2_base);
//	Timer &Timer2 = *reinterpret_cast<>(0xE000E010U);
//	Timer &Timer2 = *reinterpret_cast<>(mcal::reg::tim2_base);
//	Timer &Timer2 = *reinterpret_cast<>(0xE000E010U);
	Timer &Timer2 = *reinterpret_cast<Timer*>(mcal::reg::tim2_base);
	
//	// Enable
//	Timer2.Enable();
//	// Disable
//	Timer2.Disable();
//	// 1Hz
//	Timer2.Init_1Hz();
	tim2_init_1hz();
	
	
	
	/*Superloop*/
	while(true){
		wait_for_timeout();
		printf("Timeout!!");
	}
}
