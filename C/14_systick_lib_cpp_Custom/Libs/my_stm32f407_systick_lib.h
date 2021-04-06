#ifndef __MY_STM32F407_SYSTICK_LIB_H
#define __MY_STM32F407_SYSTICK_LIB_H

#include <stdint.h>
#include "my_stm32f407_systick_drivers.h"

/**
*
*/
class SYSTICK{
	public:
		SYSTICK();
		void DelayS(uint32_t sec);
		void DelayMs(uint32_t milli);
};

#endif // __MY_STM32F407_SYSTICK_LIB_H