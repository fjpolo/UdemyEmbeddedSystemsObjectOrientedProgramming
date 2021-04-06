#ifndef __MY_STM32F407_SYSTICK_DRIVERS_H
#define __MY_STM32F407_SYSTICK_DRIVERS_H

#include <stdint.h>

/*__IOM*/
#ifndef __IOM
#define             __IOM                    volatile
#endif // __IOM

/*__OM*/
#ifndef __OM
#define             __OM                     volatile
#endif // __OM

/*__IM*/
#ifndef __IM
#define             __IM                     volatile
#endif // __IM


#define			SCB_BASE					(0xE000E000UL)
#define			SysTick_OFFSET		(0x010UL)
#define			SysTick_BASE			SCB_BASE

/*SysTick_Type*/
#ifndef SysTick_Type
typedef struct{
	__IOM		uint32_t	CTRL;
	__IOM		uint32_t	LOAD;
	__IOM		uint32_t	VAL;
	__IM		uint32_t	CALIB;	
}SysTick_Type;
#endif //SysTick_Type

#define SysTick	((SysTick_Type*)SysTick_BASE)

#endif // __MY_STM32F407_SYSTICK_DRIVERS_H