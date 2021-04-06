#ifndef __MY_STM32F4_SYSTICK_DRIVER_H
#define	__MY_STM32F4_SYSTICK_DRIVER_H
#include <stdint.h>

#define __IOM volatile /*Read/Write structure member permssion*/
#define __OM volatile /* Write only structure member permssion*/
#define __IM volatile /*Read only structure member permssion*/


#define 		SCB_BASE			(0xE000E000UL)  /*System Control Bse Address*/


#define 		SysTick_Offset		0x010UL
#define 		SysTick_BASE		(SCB_BASE +  SysTick_Offset)



typedef struct{

__IOM  uint32_t CTRL;   
__IOM	uint32_t LOAD;    
__IOM uint32_t VAL;    
__IM	uint32_t CALIB;	
	
}SysTick_Type;


#define SysTick ((SysTick_Type *)SysTick_BASE) /*SysTick configuration structure*/
#endif