#ifndef __TIM2_H
#define __TIM2_H

/*mcal_reg*/
#include "mcal_reg.h"

/**
* Typedefs
*/

/*TimerRegister_t*/
typedef std::uint32_t volatile TimerRegister_t;
typedef void (*PointerToTimerRegister_t);
//using PointerToTimerRegister_t = void(*)();	// C++11

/*TimerModule_t*/
typedef enum{
	Timer01 = 1,
	Timer02,
	Timer03,
	Timer04,
	Timer05
}TimerModule_t;

/**
* Register defines
*/
//#define CR1_TIM2			(std::uint32_t*)std::reg::tim2_cr1
//#define CR2_TIM2			(std::uint32_t*)std::reg::tim2_cr2
//#define CR3_TIM2			(std::uint32_t*)std::reg::tim2_cr3
//#define CR4_TIM2			(std::uint32_t*)std::reg::tim2_cr4


/**
* \class Timer
*
*	\brief
*
*/
class Timer{
	public:
		/*Attributes*/
				
		/*Methods*/
		Timer();
		~Timer();
		void Enable();
		void Disable();
		std::uint32_t Get(); 
		void Init_1Hz(void);
	
	private:
		/*Attributes*/
		enum {
			TE = 0x01
		};
		TimerRegister_t CR1;							/*!<TIM CR1 Register, Address offset: 0xXX>*/
		TimerRegister_t CR2;							/*!<TIM CR2 Register, Address offset: 0xXX>*/
		TimerRegister_t SMCR;							/*!<TIM SMCR Register, Address offset: 0xXX>*/
		TimerRegister_t DIER;							/*!<TIM DIER Register, Address offset: 0xXX>*/
		TimerRegister_t SR;								/*!<TIM SR Register, Address offset: 0xXX>*/
		TimerRegister_t EGR;							/*!<TIM EGR Register, Address offset: 0xXX>*/
		TimerRegister_t CCRM1;						/*!<TIM CCRM1 Register, Address offset: 0xXX>*/
		TimerRegister_t CCRM2;						/*!<TIM CCRM2 Register, Address offset: 0xXX>*/
		TimerRegister_t CCER;							/*!<TIM CCER Register, Address offset: 0xXX>*/
		TimerRegister_t CNT;							/*!<TIM CNT Register, Address offset: 0xXX>*/
		TimerRegister_t PSC;							/*!<TIM PSC Register, Address offset: 0xXX>*/
		TimerRegister_t ARR;							/*!<TIM ARR Register, Address offset: 0xXX>*/
		TimerRegister_t RCR;							/*!<TIM RCR Register, Address offset: 0xXX>*/
		TimerRegister_t CCR1;							/*!<TIM CCR1 Register, Address offset: 0xXX>*/
		TimerRegister_t CCR2;							/*!<TIM CCR2 Register, Address offset: 0xXX>*/
		TimerRegister_t CCR3;							/*!<TIM CCR3 Register, Address offset: 0xXX>*/
		TimerRegister_t CCR4;							/*!<TIM CCR4 Register, Address offset: 0xXX>*/
		TimerRegister_t BDTR;							/*!<TIM BDTR Register, Address offset: 0xXX>*/
		TimerRegister_t DCR;							/*!<TIM DCR Register, Address offset: 0xXX>*/
		TimerRegister_t DMAR;							/*!<TIM DMAR Register, Address offset: 0xXX>*/
		TimerRegister_t OR;								/*!<TIM OR Register, Address offset: 0xXX>*/
	
	protected:
	
};





void tim2_init_1hz(void);
void wait_for_timeout(void);
void tim2_ch1_compare_mode_init(void);

#endif // __TIM2_H


