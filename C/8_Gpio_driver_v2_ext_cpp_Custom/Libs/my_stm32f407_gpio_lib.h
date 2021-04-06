#ifndef __MY_STM32F407_GPIO_LIB_H
#define __MY_STM32F407_GPIO_LIB_H

#include "my_stm32f407_gpio_drivers.h"

/**
 * Pins
 */
#define 				GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define 				GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define 				GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define 				GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define 				GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define 				GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define 				GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define 				GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define 				GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define 				GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define 				GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define 				GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define 				GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define 				GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define 				GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define 				GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define 				GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

/**
* Mode
*/
#define  				GPIO_MODE_INPUT                        0x00000000U   /*!< Input Floating Mode                   */
#define  				GPIO_MODE_OUTPUT_PP                    0x00000001U   /*!< Output Push Pull Mode                 */
#define  				GPIO_MODE_OUTPUT_OD                    0x00000011U   /*!< Output Open Drain Mode                */
#define  				GPIO_MODE_AF_PP                        0x00000002U   /*!< Alternate Function Push Pull Mode     */
#define  				GPIO_MODE_AF_OD                        0x00000012U   /*!< Alternate Function Open Drain Mode    */

/**
* Mode
*/

/**
* GPIO port pull-up/pull-down register
*/
#define  				GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  				GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  				GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation 								*/

/*PinDataType*/
#ifndef PinDataType
typedef uint32_t PinDataType;
#endif // PinDataType

/**
* Enum types
*/
/*GPIO_PinState*/
#ifndef	GPIO_PinState
typedef enum{
	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
}GPIO_PinState;
#endif //  GPIO_PinState

/*PORT_NameType*/
#ifndef	PORT_NameType
typedef enum{
	PORTA = 1,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,
	PORTI
}PORT_NameType;
#endif //  PORT_NameType

/**
* Types
*/
/*GPIO_InitTypeDef*/
#ifndef GPIO_InitTypeDef
typedef struct{
	uint32_t	Pin;
	uint32_t	Mode;
	uint32_t	Pull;
	uint32_t	Speed;
	uint32_t	Alternate;
}GPIO_InitTypeDef;
#endif // GPIO_InitTypeDef 


/**
* Classes
*/
/**/
class Gpio{
	private:
		GPIO_TypeDef 				GPIO_registerStruct;
		GPIO_InitTypeDef		GPIO_initStruct;
		PORT_NameType				GPIO_port;	
	
	public:
		Gpio(PORT_NameType _GPIO_portName, GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
		GPIO_PinState PinState(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
		void WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
		void TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
		void __LIB_RCC_GPIOA_CLK_ENABLE()const;
		void __LIB_RCC_GPIOB_CLK_ENABLE()const;
		void __LIB_RCC_GPIOC_CLK_ENABLE()const;
		void __LIB_RCC_GPIOD_CLK_ENABLE()const;
		void __LIB_RCC_GPIOE_CLK_ENABLE()const;
		void __LIB_RCC_GPIOF_CLK_ENABLE()const;
		void __LIB_RCC_GPIOG_CLK_ENABLE()const;
		void __LIB_RCC_GPIOH_CLK_ENABLE()const;
		void __LIB_RCC_GPIOI_CLK_ENABLE()const;
};

/**
* 	Functions
*/
GPIO_InitTypeDef __gpio_pin_params(PinDataType _Pin, PinDataType _Mode, PinDataType _Pull);




#endif // __MY_STM32F407_GPIO_LIB_H
