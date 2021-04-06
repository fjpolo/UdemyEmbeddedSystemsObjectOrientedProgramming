#include "led.h"


static void run_diagnostics(Led_Type const * const me);
static uint32_t compute_efficiency(Led_Type const * const me);

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
	
	
	/*Initial virtual table*/
	static const struct LedVtable vtable={
	  
		&run_diagnostics,
		&compute_efficiency
	
	};
	
	me->vptr =  &vtable;
  
	me->color  = _color;
	me->state  = _state; 

	 	
	 /*Hardware Init*/
	RCC->AHB1ENR |= LED_PORT_CLOCK;  
	
	switch(_color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


void Led_setState(Led_Type * const me,LedState_Type _state){

	 me->state =  _state;

	 
	
	switch(me->color){
		 
		case RED:
			LED_PORT->MODER |=LED_RED_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
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

static void run_diagnostics(Led_Type const * const me){
  (void)me;
}

static uint32_t compute_efficiency(Led_Type const * const me){

   (void)me;
	  return 0U;
}


/*Polymorphism at work*/


void runSystemDiagnostics(Led_Type const *led_modules[]){
int i;
  for(i =0;led_modules[i] !=(Led_Type *)0;i++){
		
		Led_runDiagnostics_vcall(led_modules[i]);
		
}

}
void computeLedEffs(Led_Type const * led_modules[]){

	
	 int i;
	   for(i =0;led_modules[i] !=(Led_Type *)0;i++){
			
       Led_computeEffi_vcall(led_modules[i]);
			 
		 }


}





