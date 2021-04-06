#include "mcal_reg.h"

// Button at PB1

/** @program: Driver to control LED at PI7 using PB1 button*/
std::int32_t button_state;

int main(void){
	/* 1. Enable clock access to GPIOB */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<1U)
											 >::reg_or();
	
	/* 2. Enable clock access to GPIOI */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<8U)
											 >::reg_or();
	
	/* 3. Set PB1 as input */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiob_moder,
												(1U<<(2*1U))								// Pin 1
											 >::reg_or();
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiob_moder,
												(1U<<((2*1U)+1U))						// Pin 1
											 >::reg_or();
											 
	/* 4. Set PI7 as output */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioi_moder,
												(0U<<(2*7U))						// Pin 7
											 >::reg_or();

	
	/*Superloop*/
	while(true){
		
		/* 5. Read PB1*/
		button_state = mcal::reg::reg_access<std::uint32_t, 
																				 std::uint32_t,
																				 mcal::reg::gpiob_idr,
																				 0U
																				>::reg_get();
		if(button_state & 0x02){
			/* 6. Toggle PI7 */
			mcal::reg::reg_access<std::uint32_t, 
														std::uint32_t, 
														mcal::reg::gpioi_bssr,
														(1U<<7U)						// Pin 7 set
														>::reg_set();	
		}
		else{
			mcal::reg::reg_access<std::uint32_t, 
														std::uint32_t, 
														mcal::reg::gpioi_bssr,
														(1U<<23U)						// Pin 7 reset
														>::reg_set();	
		}
	}
}
