#include "led.h"
#include "MedicalLed.h"
#include "PowerLed.h"







int main(void){

  USART2_Init();
	
	Led led1(RED,ON);
	
	MedicalLed mled1(INFRARED,(LedColor_Type)INFRARED,ON);
	PowerLed  pled1(RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL);
	
	
	Led const *sys_leds[] = {&led1, (Led *)&pled1,(Led *)&mled1,(Led *)0};
	


	while(1){
		
		
		//runSystemDiagnostics(sys_leds);
		computeEff(sys_leds);
		
		for(int i=0;i<600000;i++){}
	
	}



}