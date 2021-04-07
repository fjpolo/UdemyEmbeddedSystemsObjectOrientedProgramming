#ifndef __ADC_H
#define __ADC_H

#include "mcal_reg.h"

typedef std::uint32_t volatile AdcRegister_t;

/**
* \class Adc
*
* \brief
*/
class Adc{
	public:
		Adc();
		~Adc();
		void ADC1_Enable();
		void ADC1_Disable();
		void ADC1_Init(void);
		std::uint32_t ADC1_Get(void);
	
	private:
		AdcRegister_t SR;
		AdcRegister_t CR1;
		AdcRegister_t CR2;
		AdcRegister_t SMPR1;
		AdcRegister_t SMPR2;
		AdcRegister_t JOFR1;
		AdcRegister_t JOFR2;
		AdcRegister_t JOFR3;
		AdcRegister_t JOFR4;
		AdcRegister_t HTR;
		AdcRegister_t LTR;
		AdcRegister_t SQR1;
		AdcRegister_t SQR2;
		AdcRegister_t SQR3;
		AdcRegister_t JSQR;
		AdcRegister_t JDR1;
		AdcRegister_t JDR2;
		AdcRegister_t JDR3;
		AdcRegister_t JDR4;
		AdcRegister_t DR;
	
	protected:
};

void adc1_init(void);
std::uint32_t adc1_get(void);

#endif // __ADC_H
