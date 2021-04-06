#include "PowerLed.h"
#include "MedicalLed.h"



int main(void){

  USART2_Init();
	
	MedicalLed_Type mled1;
	
	MedicalLed_ctor(&mled1,INFRARED,(LedColor_Type)INFRARED,ON);

	
	while(1){
	
	}
}