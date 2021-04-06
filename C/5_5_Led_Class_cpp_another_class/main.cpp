#include "led.h"
#include "MedicalLed.h"




LedWavelength_Type lambda;


int main(void){

  USART2_Init();
	
	
	MedicalLed mled1(INFRARED,(LedColor_Type)INFRARED,ON);
	
	lambda =  mled1.MedicalLed_getWavelength();


	while(1){
	
	}
}