#include "tim3.h"

#define TIM3 ((mcal::reg::TIM_TypeDef*)mcal::reg::tim3_base)


/*tim3_init_1hz*/
void tim3_init_1hz(void){
	/*Configure Timer2 at 1Hz*/
	
	/* Enable clock timer2 */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::apb1enr,
												(1U<<0)
											 >::reg_or();
	/* Sysclock 25MHz */
	// 25000000 / 2500 = 10000
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim3_psc,
												(2500 - 1)
											 >::reg_set();
	// 10000 / 10000 = 1
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim3_arr,
												(10000 - 1)
											 >::reg_set();
											 
	/*Clear timer counter*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim3_cnt,
												(0U)
											 >::reg_set();
											 
	/*Enable timer*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim3_cr1,
												(1U<<0)
											 >::reg_set();
	
	
}

/*tim3_wait_for_timeout*/
void tim3_wait_for_timeout(void){
	
	/*Wait until UIF is set*/
	while(!(TIM3->SR & 1U));
	/*Clear UIF*/
	TIM3->SR &= ~1U;

}




