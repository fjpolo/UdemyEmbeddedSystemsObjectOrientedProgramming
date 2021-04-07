#include "systick.h"
#include "mcal_reg.h"

// SysTick Registers struct pointer
//mcal::reg::SYSTICK_TypeDef * SYSTICK = ((mcal::reg::SYSTICK_TypeDef *)mcal::reg::systick_base);
#define SYSTICK		((mcal::reg::SYSTICK_TypeDef *)mcal::reg::systick_base)


void systick_init_1sec(void){
	//
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_load,
												(16000000-1)
											 >::reg_set();
	
	// 
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_val,
												(0)
											 >::reg_set();
	
	// Enable systick, use system clock, no interrupt
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_ctrl,
												(5)
											 >::reg_set();
}
int systick_get_count_flag(void){
	return SYSTICK->CTRL & 0x10000U;
}

void systick_delayMs(std::uint32_t ms){
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_load,
												(16000-1)									 // 1mS
											 >::reg_set();
	
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_val,
												(0)
											 >::reg_set();
	
	// Enable systick, use system clock, no interrupt
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_ctrl,
												(5)
											 >::reg_set();
	
	std::uint32_t state;
	for(int i=0; i<ms; i++){
		// Wait uintil count flag is set
		while(!(SYSTICK->CTRL & 0x10000U));
	}
	
	// Disable systick
	mcal::reg::reg_access<std::uint32_t,
												std::uint32_t,
												mcal::reg::systick_ctrl,
												(0)
											 >::reg_set();
}
