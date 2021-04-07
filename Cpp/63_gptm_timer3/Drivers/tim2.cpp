#include "tim2.h"

#define TIM2 ((mcal::reg::TIM_TypeDef*)mcal::reg::tim2_base)


/*tim2_init_1hz*/
void tim2_init_1hz(void){
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
												mcal::reg::tim2_psc,
												(2500 - 1)
											 >::reg_set();
	// 10000 / 10000 = 1
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_arr,
												(10000 - 1)
											 >::reg_set();
											 
	/*Clear timer counter*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_cnt,
												(0U)
											 >::reg_set();
											 
	/*Enable timer*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_cr1,
												(1U<<0)
											 >::reg_set();
	
	
}

/*wait_for_timeout*/
void wait_for_timeout(void){
	
	/*Wait until UIF is set*/
	while(!(TIM2->SR & 1U));
	/*Clear UIF*/
	TIM2->SR &= ~1U;

}




/**
* \class Timer
*
*	\brief
*
*/

/*Constructor*/
Timer::Timer(){
	/*Switch TimerModule*/
//	switch(this->TimerModule){
//		case Timer02:
//		{
////			CR1 = static_cast<TimerRegister_t>(mcal::reg::tim2_cr1);
////			CR2 = static_cast<TimerRegister_t>(mcal::reg::tim2_cr2);							
////			SMCR = static_cast<TimerRegister_t>(mcal::reg::tim2_smcr);				
////			DIER = static_cast<TimerRegister_t>(mcal::reg::tim2_dier);
////			SR = static_cast<TimerRegister_t>(mcal::reg::tim2_sr);
////			EGR = static_cast<TimerRegister_t>(mcal::reg::tim2_egr);
////			CCRM1 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccmr1);	
////			CCRM2 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccmr2);
////			CCER = static_cast<TimerRegister_t>(mcal::reg::tim2_ccer);
////			CNT = static_cast<TimerRegister_t>(mcal::reg::tim2_cnt);
////			PSC = static_cast<TimerRegister_t>(mcal::reg::tim2_psc);
////			ARR = static_cast<TimerRegister_t>(mcal::reg::tim2_arr);
////			CCR1 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccr1);
////			CCR2 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccr2);
////			CCR3 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccr3);
////			CCR4 = static_cast<TimerRegister_t>(mcal::reg::tim2_ccr4);
////			DCR = static_cast<TimerRegister_t>(mcal::reg::tim2_dcr);
////			DMAR = static_cast<TimerRegister_t>(mcal::reg::tim2_dmar);
////			OR = static_cast<TimerRegister_t>(mcal::reg::tim2_or);
			
//			CR1 = (mcal::reg::tim2_cr1);
//			CR2 = (mcal::reg::tim2_cr2);							
//			SMCR = (mcal::reg::tim2_smcr);				
//			DIER = (mcal::reg::tim2_dier);
//			SR = (mcal::reg::tim2_sr);
//			EGR = (mcal::reg::tim2_egr);
//			CCRM1 = (mcal::reg::tim2_ccmr1);	
//			CCRM2 = (mcal::reg::tim2_ccmr2);
//			CCER = (mcal::reg::tim2_ccer);
//			CNT = (mcal::reg::tim2_cnt);
//			PSC = (mcal::reg::tim2_psc);
//			ARR = (mcal::reg::tim2_arr);
//			CCR1 = (mcal::reg::tim2_ccr1);
//			CCR2 = (mcal::reg::tim2_ccr2);
//			CCR3 = (mcal::reg::tim2_ccr3);
//			CCR4 = (mcal::reg::tim2_ccr4);
//			DCR = (mcal::reg::tim2_dcr);
//			DMAR = (mcal::reg::tim2_dmar);
//			OR = (mcal::reg::tim2_or);	
//		
//		}
//			
//		default:
//		{
//			break;
//		}
//	}
}
/*Destructor*/
Timer::~Timer(){}
/*Enable*/
void Timer::Enable(){
	CR1 |= TE;
}
/*Disable*/
void Timer::Disable(){
	CR1 &= ~TE;
}
	
/*Init_1Hz*/
void Timer::Init_1Hz(void){
	/**
	* Configure Timer at 1Hz
	*/
	
	/* Enable clock timer2 */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::apb1enr,
												(1U<<0)
											 >::reg_or();
	
	/* Sysclock 25MHz */
	// 25000000 / 2500 = 10000
	PSC = (2500 - 1);
	
	// 10000 / 10000 = 1
	ARR = (10000 - 1);
	
	/*Clear timer counter*/
	CNT = 0;
	
	this->CR2 = 0x05;
	this->SMCR = 0x06;
	this->SR = 0x07;
	this->CCRM1 = 0x08;
	this->CCRM2 = 0x09;
	this->CCER = 0x0A;
	this->CNT = 0x0B;
	this->PSC = 0x0C;
	this->ARR = 0x0D;
	this->DCR = 0x0E;
	this->DMAR = 0x0F;
	
	/*Enable timer*/
	this->Enable();
	
}


