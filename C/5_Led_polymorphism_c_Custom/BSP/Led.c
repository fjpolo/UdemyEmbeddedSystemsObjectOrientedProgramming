#include "led.h"

#ifdef __cplusplus
extern "C" {
#endif	//__cplusplus

static void run_diagnostics(Led_Type const * const me);
static uint32_t compute_efficiency(Led_Type const * const me);

	
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){
	/*Virtual table*/
	static const struct LedVtable vtable={
		&run_diagnostics,
		&compute_efficiency
	};
	me->vptr = &vtable;
		
	/**/
	me->color  = _color;
	me->state  = _state; 
	/*USART6_Init*/
	USART6_Init();
	/*GPIO Init*/
	MX_GPIO_Init();
}


void Led_setState(Led_Type * const me, LedState_Type _state){
	 me->state =  _state;
	// printf("The %d led  is  set to  %d \n\r",me->color, me->state);
	
	/**/ 
	switch(me->color){	
		case RED:
		{
			//printf("RED set to: %d \n\r", me->state);
			if(me->state  == ON){
					RED_LED_PORT->ODR &= ~RED_LED_PIN;
					printf("RED set to ON \n\r");
			}
			else{
			  RED_LED_PORT->ODR |= RED_LED_PIN;
				printf("RED set to OFF \n\r");
			}
			break;		
		}
	  case GREEN:
		{
			//printf("GREEN set to: %d \n\r", me->state);
			if(me->state  == ON){
					GREEN_LED_PORT->ODR &= ~GREEN_LED_PIN;
					printf("GREEN set to ON \n\r");
			}
			else{
        GREEN_LED_PORT->ODR |= GREEN_LED_PIN;
				printf("GREEN set to OFF \n\r");
			}
			break;
		}
		case YELLOW:
		{
			//printf("YELLOW set to: %d \n\r", me->state);
			if(me->state  == ON){
					YELLOW_LED_PORT->ODR &= ~YELLOW_LED_PIN;
					printf("YELLOW set to ON \n\r");
			}
			else{
        YELLOW_LED_PORT->ODR |= YELLOW_LED_PIN;
				printf("YELLOW set to OFF \n\r");
			}
			break;	
		}
		default:
		{
			printf("Invalid!\n");
			break;
		}
	 }
}

/*Virtual functions*/
static void run_diagnostics(Led_Type const * const me){(void)me;}
static uint32_t compute_efficiency(Led_Type const * const me){
	(void)me;
	return 0U;
}


LedState_Type Led_getState(Led_Type * const me){
	/**/
	switch(me->color){
		case RED:
		{
			printf("RED State: %d \n\r", me->state);
				 break;	
		}
	  case GREEN:
		{
			printf("GREEN State: %d \n\r", me->state);
				 break;
		}
		case YELLOW:
		{
			   printf("YELLOW State:  %d \n\r", me->state);
				 break;		
		}
		default:
		{
			printf("Invalid!\n");
			break;
		}
	 }
  
	return me->state;
}


/*Polymorphism*/
void runSystemDiagnostics(Led_Type const * led_modules[]){
	for(int i=0;led_modules[i]!=(Led_Type*)0;i++){
		Led_run_diagnostics_vcall(led_modules[i]);
	}
}
void computeLedEffs(Led_Type const * led_modules[]){
	for(int i=0;led_modules[i]!=(Led_Type*)0;i++){
		Led_compute_efficiency_vcall(led_modules[i]);
	}
}

#ifdef __cplusplus
}
#endif	//__cplusplus

	