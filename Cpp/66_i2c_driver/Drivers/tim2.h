#pragma once


/*mcal_reg*/
#include <stddef.h>
#include "mcal_reg.h"
#include <stddef.h>


/**
* Typedefs
*/

/*TimerRegister_t*/
////using PointerToTimerRegister_t = void(*)();	// C++11
//typedef std::uint32_t volatile TimerRegister_t;
using TimerRegister_t = std::uint32_t volatile;

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
#pragma pack(push, 1)
class Timer{
	private:
		/*Attributes*/
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
	
	public:
		/*Attributes*/
		enum Bitmasks{
			TE = 0x01
		};
		enum TimerModules : std::uint8_t{
			Module2 = 0,
			Module3,
			Module4,
			Module5
		};
				
		TimerModules module;
		
		/*Methods*/
		Timer() = default;
		Timer(TimerModules _module);
		~Timer();
		void *operator new(std::size_t size, TimerModules _module){
			auto address = mcal::reg::tim2_base + (_module * mcal::reg::tim_offset);
			return reinterpret_cast<void *>(address);
		}
		void Enable();
		void Disable();
		std::uint32_t Get(); 
		void Init_1Hz(void);
		void InitCh1CompareMode(void);
		void WaitForTimeout(void);
		
	protected:
		
};
#pragma pack(pop)

/*Assertions*/
//static_assert( offsetof(Timer, CR1) == 4) , "ERROR: Timer.CR1 misaligned!");
//static_assert( offsetof(Timer, CR2) == 4) , "ERROR: Timer.CR2 misaligned!");
//static_assert( offsetof(Timer, SMCR) == 4) , "ERROR: Timer.SMCR misaligned!");
//static_assert( offsetof(Timer, DIER) == 4) , "ERROR: Timer.DIER misaligned!");
//static_assert( offsetof(Timer, SR) == 4) , "ERROR: Timer.SR misaligned!");
//static_assert( offsetof(Timer, EGR) == 4) , "ERROR: Timer.EGR misaligned!");
//static_assert( offsetof(Timer, CCRM1) == 4) , "ERROR: Timer.CCRM1 misaligned!");
//static_assert( offsetof(Timer, CCRM2) == 4) , "ERROR: Timer.CCRM2 misaligned!");
//static_assert( offsetof(Timer, CCER) == 4) , "ERROR: Timer.CCER misaligned!");
//static_assert( offsetof(Timer, CNT) == 4) , "ERROR: Timer.CNT misaligned!");
//static_assert( offsetof(Timer, PSC) == 4) , "ERROR: Timer.PSC misaligned!");
//static_assert( offsetof(Timer, ARR) == 4) , "ERROR: Timer.ARR misaligned!");
//static_assert( offsetof(Timer, RCR) == 4) , "ERROR: Timer.RCR misaligned!");
//static_assert( offsetof(Timer, CCR1) == 4) , "ERROR: Timer.CCR1 misaligned!");
//static_assert( offsetof(Timer, CCR2) == 4) , "ERROR: Timer.CCR2 misaligned!");
//static_assert( offsetof(Timer, CCR3) == 4) , "ERROR: Timer.CCR3 misaligned!");
//static_assert( offsetof(Timer, CCR4) == 4) , "ERROR: Timer.CCR4 misaligned!");
//static_assert( offsetof(Timer, BDTR) == 4) , "ERROR: Timer.BDTR misaligned!");
//static_assert( offsetof(Timer, DCR) == 4) , "ERROR: Timer.DCR misaligned!");
//static_assert( offsetof(Timer, DMAR) == 4) , "ERROR: Timer.DMAR misaligned!");
//static_assert( offsetof(Timer, OR) == 4) , "ERROR: Timer.OR misaligned!");
//static_assert( sizeof(Timer) == (21 * sizeof(TimerRegister_t), "ERROR: Timer has some padding bytes!!");




void tim2_init_1hz(void);
void wait_for_timeout(void);
void tim2_ch1_compare_mode_init(void);



