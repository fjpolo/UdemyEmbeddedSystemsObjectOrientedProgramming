#ifndef __MY_STM32F407_SYSTICK_LIB_H
#define __MY_STM32F407_SYSTICK_LIB_H

#include <stdint.h>
#include "my_stm32f407_systick_drivers.h"

void LIB_SYSTICK_Delay(uint32_t sec);
void LIB_SYSTICK_DelayMs(uint32_t milli);


#endif // __MY_STM32F407_SYSTICK_LIB_H