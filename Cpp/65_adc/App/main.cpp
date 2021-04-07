#include "uart.h"
#include "stdio.h"
#include "adc.h"


std::uint32_t sensorVal;
Adc &Adc1 = *reinterpret_cast<Adc*>(mcal::reg::adc1_base); 

int main(void){			
	/*Init USART6*/
	uart6_init();
	/*ADC1 Init*/
//	adc1_init();
	Adc1.ADC1_Init();
	
	/*Superloop*/
	while(true){
		/*Read ADC*/
//		sensorVal = adc1_get();		
		sensorVal = Adc1.ADC1_Get();
	}
}
