#include "led.h"


Led led1(RED,ON);


LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

int main(void){

  USART2_Init();

	Led led2(BLUE,ON);
	
	Led *led3 =  new Led(YELLOW,ON);
	
	led1_state = led1.getState();
	led2_state = led2.getState();
	
	led3_state = led3->getState();
	
	led1.setState(OFF);
	led2.setState(OFF);
	led3->setState(OFF);
	
	
	
	delete led3;
	while(1){
	
	}
}