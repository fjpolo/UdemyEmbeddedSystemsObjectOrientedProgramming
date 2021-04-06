#include  "my_stm32f4_gpio_lib.h"
#include  "my_stm32f4_systick_lib.h"




GPIO_InitTypeDef myGPIO_InitStruct;

int main(void){

	__LIB_RCC_GPIOA_CLK_ENABLE();
	
	myGPIO_InitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
	myGPIO_InitStruct.Pin  = GPIO_PIN_5;
	myGPIO_InitStruct.Pull = GPIO_NOPULL;
	
	LIB_GPIO_Init(GPIOA,&myGPIO_InitStruct);
	


	while(1){
		
	 LIB_SYSTICK_DelayMs(500);
	 LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
  
	
   
}

}






