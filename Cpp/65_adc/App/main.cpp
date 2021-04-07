#include "uart.h"
#include "stdio.h"
#include "adc.h"


std::uint32_t sensorVal;

int main(void){			
	/*Init USART6*/
	uart6_init();
	/*ADC1 Init*/
	adc1_init();
	
	/*Superloop*/
	while(true){
		/*Read ADC*/
		sensorVal = adc1_get();		
	}
}
