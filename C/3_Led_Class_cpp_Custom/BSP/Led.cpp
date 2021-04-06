#include "led.h"

	
Led::Led(LedColor_Type _color, LedState_Type _state)
				:color  (_color),
				 state  (_state)
{ 
	/*Option 2*/
	//this->color = _color;
	//this-Ystat = _state;
	//
	/*GPIO Init*/
	MX_GPIO_Init();
}


void Led::setState(LedState_Type _state){
	 this->state =  _state;
	// printf("The %d led  is  set to  %d \n\r",this->color, this->state);
	
	/**/ 
	switch(this->color){	
		case RED:
		{
			//printf("RED set to: %d \n\r", this->state);
			if(this->state  == ON){
					RED_LED_PORT->ODR &= ~RED_LED_PIN;
			}
			else{
			  RED_LED_PORT->ODR |= RED_LED_PIN;
			}
			break;		
		}
	  case GREEN:
		{
			//printf("GREEN set to: %d \n\r", this->state);
			if(this->state  == ON){
					GREEN_LED_PORT->ODR &= ~GREEN_LED_PIN;
			}
			else{
        GREEN_LED_PORT->ODR |= GREEN_LED_PIN;
			}
			break;
		}
		case YELLOW:
		{
			//printf("YELLOW set to: %d \n\r", this->state);
			if(this->state  == ON){
					YELLOW_LED_PORT->ODR &= ~YELLOW_LED_PIN;
			}
			else{
        YELLOW_LED_PORT->ODR |= YELLOW_LED_PIN;
			}
			break;	
		}
		default:
		{
			break;
		}
	 }
}


LedState_Type Led::getState()const{
	/**/
	switch(this->color){
		case RED:
		{
				 break;	
		}
	  case GREEN:
		{
				 break;
		}
		case YELLOW:
		{
				 break;		
		}
		default:
		{
			break;
		}
	 }
  
	return this->state;
}
