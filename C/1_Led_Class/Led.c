#include "led.h"


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
  
	me->color  = _color;
	me->state  = _state; 

}


void Led_setState(Led_Type * const me,LedState_Type _state){

	 me->state =  _state;
	
	// printf("The %d led  is  set to  %d \n\r",me->color, me->state);
	
	 
	switch(me->color){
		
		case RED:
			   printf("The RED Led is set to %d \n\r",me->state);
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is set to %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is set to %d \n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is set to %d \n\r",me->state);
				 break;
		
		
	 }
}


LedState_Type Led_getState(Led_Type * const me){

	switch(me->color){
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state);
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state);
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state);
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state);
				 break;
		
		
	 }
  
	return me->state;
}
