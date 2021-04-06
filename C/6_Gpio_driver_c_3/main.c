#include  "my_stm32f4_gpio_driver.h"



int main(void){

   RCC->AHB1ENR |= GPIOA_EN | GPIOB_EN; 
	
	 GPIOA->MODER |= MODER_5_OUT;
	 GPIOB->MODER	|= MODER_5_OUT;
	
	
	while(1){
	   for(int i =0;i< 900000;i++){}
			 GPIOA->ODR ^=LED_PIN;
			 GPIOB->ODR ^=LED_PIN;
	}
   
}









