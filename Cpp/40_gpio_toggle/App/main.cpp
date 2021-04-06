#include "mcal_reg.h"


/** @program: Driver to toggle PI7*/
int main(void){
	/* 1. Enable clock access to GPIOI */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<8U)
											 >::reg_or();
	
	/* 2. Set PI7 as output */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioi_moder,
												(1U<<(2*7U))						// Pin 7
											 >::reg_or();
	
	/*Superloop*/
	while(true){
		/* 3. Toggle PI7 */
		mcal::reg::reg_access<std::uint32_t, 
													std::uint32_t, 
													mcal::reg::gpioi_odr,
													(7U)						// Pin 7
													>::reg_not();	
		for(int i=0;i<1000;i++);
	}
}
