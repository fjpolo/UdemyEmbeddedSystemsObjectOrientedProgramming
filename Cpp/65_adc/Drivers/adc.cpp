#include "adc.h"

#define ADC1	((mcal::reg::ADC_TypeDef*)mcal::reg::adc1_base)

void adc1_init(void){
	
	/*Enable clock access to PA1*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::ahb1enr,
												(1U<<0)
											 >::reg_or();
	
	/*Configure PA1 as analog*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<2)
											 >::reg_or();
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<3)
											 >::reg_or();
//	mcal::reg::reg_access<
//												std::uint32_t,
//												std::uint32_t,
//												mcal::reg::ahb1enr,
//												(0x0C)
//											 >::reg_or();
	
	/*Enable clock access to adc1*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::apb2enr,
												(1U<<8)
											 >::reg_or();
	
	/*SW trigger*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::adc1_cr2,
												(0x00)
											 >::reg_set();
	
	/*Conversion sequence starts at channel1*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::adc1_sqr3,
												(1U<<0)
											 >::reg_set();
	
	
	/*Conversion sequence length*/	
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::adc1_sqr1,
												(0x00)
											 >::reg_set();
	
	/*Enable ADC*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::adc1_cr2,
												(1U<<0)
											 >::reg_or();
	
}

/*adc1_get*/
std::uint32_t adc1_get(void){
	/*Start conversion*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::adc1_cr2,
												(1U<<30)
											 >::reg_or();
	
	/*Wait for conversion*/
	while(!(ADC1->SR) & (0x02)){}
	
	/*Read value from data register*/
	return mcal::reg::reg_access<
																std::uint32_t,
																std::uint32_t,
																mcal::reg::adc1_dr,
																(0)
															>::reg_get();
	
}









/**
* \class Adc
*
* \brief
*/
Adc::Adc(){}
Adc::~Adc(){}
void Adc::ADC1_Enable(){
	CR2 |= 0x01;
}
void Adc::ADC1_Disable(){
	CR2 &= ~0x01;
}
void Adc::ADC1_Init(void){
	/*Enable clock access to PA1*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::ahb1enr,
												(1U<<0)
											 >::reg_or();
	
	/*Configure PA1 as analog*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<2)
											 >::reg_or();
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::gpioa_moder,
												(1U<<3)
											 >::reg_or();
//	mcal::reg::reg_access<
//												std::uint32_t,
//												std::uint32_t,
//												mcal::reg::ahb1enr,
//												(0x0C)
//											 >::reg_or();
	
	/*Enable clock access to adc1*/
	mcal::reg::reg_access<
												std::uint32_t,
												std::uint32_t,
												mcal::reg::apb2enr,
												(1U<<8)
											 >::reg_or();
	
	/*SW trigger*/
	CR2 = 0;
	
	/*Conversion sequence starts at channel1*/
	SQR3 = 0x01;
	
	
	/*Conversion sequence length*/
	SQR1 = 0x00;	

	
	/*Enable ADC*/
	this->ADC1_Enable();
	
}
std::uint32_t Adc::ADC1_Get(void){
	/*Start conversion*/
	CR2 |= (1U<<30);

	
	/*Wait for conversion*/
	while(!(SR & 0x02)){}
	
	/*Read value from data register*/
	return DR;
}