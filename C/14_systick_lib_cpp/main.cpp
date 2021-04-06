#include  "my_stm32f4_gpio_lib.h"
#include  "my_stm32f4_systick_lib.h"




SYSTICK delayTimer;
GPIO_InitTypeDef  myGPIO_InitStruct;

int main(void){

	
	myGPIO_InitStruct=  __gpio_pin_params(GPIO_PIN_5,GPIO_MODE_OUTPUT_PP,GPIO_NOPULL);
	
	 Gpio myOutput1(PORTA,GPIOA,&myGPIO_InitStruct);


	while(1){
		
		delayTimer.LIB_SYSTICK_DelayMs(500);
		myOutput1.LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);

	
   
}

}





