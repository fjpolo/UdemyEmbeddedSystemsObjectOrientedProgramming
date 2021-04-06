#include "PowerLed.h"
#include "MedicalLed.h"



int main(void){

  USART2_Init();
	
	MedicalLed_Type  mled1;
	PowerLed_Type pled1;
	Led_Type      led1;
	
	
	Led_ctor(&led1,RED,ON);
	PowerLed_ctor(&pled1,RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);
	MedicalLed_ctor(&mled1,INFRARED,(LedColor_Type)INFRARED,ON);
	
	Led_Type const * sys_leds[] = {&led1,(Led_Type*)&pled1,(Led_Type*)&mled1,(Led_Type*)0};

	
	  
	while(1){
	
	  //runSystemDiagnostics(sys_leds);
		
		computeLedEffs(sys_leds);
		for(int i=0;i<6000000;i++){}
	
		
	}
}