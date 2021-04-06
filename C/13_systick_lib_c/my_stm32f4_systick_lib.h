#ifndef __MY_STM32F4_SYSTICK_LIB
#define __MY_STM32F4_SYSTICK_LIB

#include  "my_stm32f4_systick_driver.h"

void LIB_SYSTICK_Delay(uint32_t sec);
void LIB_SYSTICK_DelayMs(uint32_t milli);

#endif