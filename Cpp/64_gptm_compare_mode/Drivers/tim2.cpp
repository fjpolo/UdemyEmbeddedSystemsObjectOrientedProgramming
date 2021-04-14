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
											 
	/*Enable timer2*/
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

void tim2_ch1_compare_mode_init(void){
	/**Enable clock for GPIOA*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::ahb1enr,
												0x01
											 >::reg_or();
	
	/*Set PA5 to alternate functions*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(0U<<10)
											 >::reg_or();
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<11)
											 >::reg_or();
	
	/*Select AF1 i.e. TIM2*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_afrl,
												(1U<<20)
											 >::reg_or();
	/*Enable clock access to TIM2*/
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
											 
	/*Set output to toggle on match*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_ccmr1,
												(0x30)
											 >::reg_set();
	
	/*Set match value*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_ccr1,
												(0x00)
											 >::reg_set();
											 
	/*Enable CH5 compare mode*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_ccer,
												(1U<<0)
											 >::reg_set();

	/*Clear timer counter*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_cnt,
												(0U)
											 >::reg_set();

	/*Enable timer2*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::tim2_cr1,
												(1U<<0)
											 >::reg_set();
}



/**
* \class Timer
*
*	\brief
*
*/

/*Constructor*/
Timer::Timer(TimerModules _module)
:module(_module)
{
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
	
	/*Disable timer2*/
	this->Disable();
	
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
	
	/*Test registers*/
//	this->CR2 = 0x05;
//	this->SMCR = 0x06;
//	this->SR = 0x07;
//	this->CCRM1 = 0x08;
//	this->CCRM2 = 0x09;
//	this->CCER = 0x0A;
//	this->CNT = 0x0B;
//	this->PSC = 0x0C;
//	this->ARR = 0x0D;
//	this->DCR = 0x0E;
//	this->DMAR = 0x0F;
	
	/*Enable timer*/
	this->Enable();
	
}
/*InitCh1CompareMode*/
void Timer::InitCh1CompareMode(void){
	
	/*Disable timer2*/
	this->Disable();
	
	/**Enable clock for GPIOA*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::ahb1enr,
												0x01
											 >::reg_or();
	
	/*Set PA5 to alternate functions*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(0U<<10)
											 >::reg_or();
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<11)
											 >::reg_or();
	
	/*Select AF1 i.e. TIM2*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_afrl,
												(1U<<20)
											 >::reg_or();
	/*Enable clock access to TIM2*/
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::apb1enr,
												(1U<<0)
											 >::reg_or();
											 
											 
	/* Sysclock 25MHz */
	// 25000000 / 2500 = 10000
	this->PSC = (2500 - 1);
	
	// 10000 / 10000 = 1
	this->ARR = 10000 - 1;
	
	/*Set output to toggle on match*/
	this->CCRM1 = 0x30;
	
	/*Set match value*/
	this->CCR1 = 0x00;
											 
	/*Enable CH5 compare mode*/
	this->CCER = (1U<<0);

	/*Clear timer counter*/
	this->CNT = 0U;

	/*Enable timer2*/
	this->Enable();
}
/*WaitForTimeout*/
void Timer::WaitForTimeout(void){
	/*Wait until UIF is set*/
	while(!(this->SR & 1U));
	/*Clear UIF*/
	this->SR &= ~1U;
}




