#ifndef		__MY_STM32F4_GPIO_LIB_H__
#define		__MY_STM32F4_GPIO_LIB_H__

#include  "my_stm32f4_gpio_driver.h"

#define GPIO_PIN_0				((uint16_t)0x0001) 
#define GPIO_PIN_1				((uint16_t)0x0002) 
#define GPIO_PIN_2				((uint16_t)0x0004) 
#define GPIO_PIN_3				((uint16_t)0x0008) 
#define GPIO_PIN_4				((uint16_t)0x0010) 
#define GPIO_PIN_5				((uint16_t)0x0020) 
#define GPIO_PIN_6				((uint16_t)0x0040) 
#define GPIO_PIN_7				((uint16_t)0x0080) 
#define GPIO_PIN_8				((uint16_t)0x0100) 
#define GPIO_PIN_9				((uint16_t)0x0200) 
#define GPIO_PIN_10				((uint16_t)0x0400) 
#define GPIO_PIN_11				((uint16_t)0x0800) 
#define GPIO_PIN_12				((uint16_t)0x1000) 
#define GPIO_PIN_13				((uint16_t)0x2000) 
#define GPIO_PIN_14				((uint16_t)0x4000) 
#define GPIO_PIN_15				((uint16_t)0x8000) 
#define GPIO_PIN_ALL			((uint16_t)0xFFFF) 


#define		GPIO_MODE_INPUT				0x00U

#define		GPIO_MODE_OUTPUT_PP		0x11U
#define		GPIO_MODE_OUTPUT_OD		0x01U
#define		GPIO_MODE_AF_PP				0x02U
#define 	GPIO_MODE_AF_OD				0x12U

#define		GPIO_NOPULL					0x00U
#define		GPIO_PULLUP					0x01U	
#define		GPIO_PULLDOWN				0x02U   //  0B  0000 0010


typedef struct{
	uint32_t 		Pin;
	uint32_t    Mode;
	uint32_t 		Pull;
	uint32_t 		Speed;
	uint32_t 		Alternate;
	
}GPIO_InitTypeDef;


typedef enum{
GPIO_PIN_RESET =0,
GPIO_PIN_SET
}GPIO_PinState;




void LIB_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_InitTypeDef *GPIO_Init);
GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin,GPIO_PinState PinState);
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void __LIB_RCC_GPIOA_CLK_ENABLE(void);
void __LIB_RCC_GPIOB_CLK_ENABLE(void);
void __LIB_RCC_GPIOC_CLK_ENABLE(void);
void __LIB_RCC_GPIOD_CLK_ENABLE(void);
void __LIB_RCC_GPIOE_CLK_ENABLE(void);
void __LIB_RCC_GPIOH_CLK_ENABLE(void);



#endif