#include  "my_stm32f4_gpio_lib.h"

uint8_t btnState;

int main()
{
	
	GPIO_InitTypeDef	 myGpio_InitStruct;
  /*Test 1*/
  /* myGpio_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   myGpio_InitStruct.Pin  = GPIO_PIN_5;
   myGpio_InitStruct.Pull = GPIO_NOPULL;*/
	
	
	myGpio_InitStruct =  __gpio_pin_params(GPIO_PIN_5,GPIO_MODE_OUTPUT_PP,GPIO_NOPULL);
	Gpio myOutput1(PORTA,GPIOA,&myGpio_InitStruct);
	
	/*Test 2 -  Add another port, same pin */
  Gpio myOutput2(PORTC,GPIOC,&myGpio_InitStruct);
	
	/*Test 3 -  Another port, different pin*/
	myGpio_InitStruct =  __gpio_pin_params(GPIO_PIN_13,GPIO_MODE_OUTPUT_PP,GPIO_NOPULL);
	Gpio myOutput3(PORTD,GPIOD,&myGpio_InitStruct);
	
	/*Test 4   - Another port different mode*/
	myGpio_InitStruct  =  __gpio_pin_params(GPIO_PIN_13,GPIO_MODE_INPUT,GPIO_NOPULL);
	Gpio myInput1(PORTC,GPIOC,&myGpio_InitStruct);
	while(1){
	
		for(int i=0;i<900000;i++){}
			
		myOutput1.LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		myOutput2.LIB_GPIO_TogglePin(GPIOC,GPIO_PIN_5);
		myOutput3.LIB_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
			
		
			/*Button is active low on  nucleo-f411*/
			btnState = myInput1.LIB_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
	
	}
}
