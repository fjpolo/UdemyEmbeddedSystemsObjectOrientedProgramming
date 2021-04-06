#include "led.h"


 Led::Led(LedColor_Type _color, LedState_Type _state)
   /*Option 2*/
// :color(_color),
//  state(_state)
 {
  
	 /*Option 1*/
	this->color  = _color;
	this->state  = _state; 

	 	
	 /*Hardware Init*/
	RCC->AHB1ENR |= LED_PORT_CLOCK;  
	
	switch(_color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(this ->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;

			}
		break;
	
	}
}


void Led::setState(LedState_Type _state){

	 this->state =  _state;

	 
	
	switch(this->color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(this->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;

			}
		break;
	
	}
}


LedState_Type Led::getState(void)const{

	switch(this->color){
		
		case RED:
				 break;
		
	  case GREEN:
				 break;
		case BLUE:
				 break;
		case YELLOW:
				 break;
		
		
	 }
  
	return this->state;
}
