#include  "my_stm32f4_gpio_lib.h"
#include  "my_stm32f4_systick_driver.h"




GPIO_InitTypeDef myGPIO_InitStruct;

int main(void){

	__LIB_RCC_GPIOA_CLK_ENABLE();
	
	myGPIO_InitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin  = GPIO_PIN_5;
	myGPIO_InitStruct.Pull = GPIO_NOPULL;
	
	LIB_GPIO_Init(GPIOA,&myGPIO_InitStruct);
	
	/*Configure SysTick*/
	SysTick->LOAD =  16000000 -1;
	SysTick->VAL =0;
	SysTick->CTRL = 5;


	while(1){
		
   if(SysTick->CTRL & 0x10000){
		 LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
  
	}
   
}

}






