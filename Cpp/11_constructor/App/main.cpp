#include "mcal_reg.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>

/*
		RED LED PI5
		GPIOI = AHB1
		GPIOI = 0x4002 1C00
		MODEREG OFFSET = 0x00
		
typedef struct{
    __IO    uint32_t    MODER;          // GPIO port mode register
    __IO    uint32_t    OTYPER;
    __IO    uint32_t    OSPEEDR;    
    __IO    uint32_t    PUPDR;
    __IO    uint32_t    IDR;
    __IO    uint32_t    ODR;
    __IO    uint32_t    BSRR;
    __IO    uint32_t    LCKR;
    __IO    uint32_t    AFL[2]; 
}GPIO_TypeDef;


typedef struct{
    __IO    uint32_t    CR;             // RCC clock control register
    __IO    uint32_t    PLLCFGR;        // RCC PLL configuration register
    __IO    uint32_t    CFGR;           // RCC clock configuration register
    __IO    uint32_t    CIR;            // RCC clock interrupt register
    __IO    uint32_t    AHB1RSTR;       // RCC AHB1 peripheral reset register
    __IO    uint32_t    AHB2RSTR;       // RCC AHB2 peripheral reset register
    __IO    uint32_t    AHB3RSTR;       // RCC AHB3 peripheral reset register
    __IO    uint32_t    DUMMY1;         // Dummy 32 bits
    __IO    uint32_t    APB1RSTR;       // RCC APB1 peripheral reset register
    __IO    uint32_t    APB2RSTR;       // RCC APB2 peripheral reset register
    __IO    uint32_t    DUMMY2;         // Dummy 32 bits
    __IO    uint32_t    DUMMY3;         // Dummy 32 bits
    __IO    uint32_t    AHB1ENR;        // RCC AHB1 peripheral clock enable register
    __IO    uint32_t    AHB2ENR;        // RCC AHB2 peripheral clock enable register
    __IO    uint32_t    AHB3ENR;        // RCC AHB3 peripheral clock enable register
    __IO    uint32_t    DUMMY4;         // Dummy 32 bits
    __IO    uint32_t    APB1ENR;        // RCC APB1 peripheral clock enable register
    __IO    uint32_t    APB2ENR;        // RCC APB2 peripheral clock enable register
    __IO    uint32_t    DUMMY5;         // Dummy 32 bits
    __IO    uint32_t    DUMMY6;         // Dummy 32 bits
    __IO    uint32_t    AHB1LPENR;      // RCC AHB1 peripheral clock enable in low power mode register     
    __IO    uint32_t    AHB2LPENR;      // RCC AHB2 peripheral clock enable in low power mode register
    __IO    uint32_t    AHB3LPENR;      // RCC AHB3 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY7;         // Dummy 32 bits
    __IO    uint32_t    APB1LPENR;      // RCC APB1 peripheral clock enable in low power mode register
    __IO    uint32_t    APB2LPENR;      // RCC APB2 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY8;         // Dummy 32 bits
    __IO    uint32_t    DUMMY9;         // Dummy 32 bits
    __IO    uint32_t    BDCR;           // RCC Backup domain control register (
    __IO    uint32_t    CSR;            // RCC clock control & status register
    __IO    uint32_t    DUMMY10;        // Dummy 32 bits
    __IO    uint32_t    DUMMY11;        // Dummy 32 bits
    __IO    uint32_t    SSCGR;          // RCC spread spectrum clock generation register
    __IO    uint32_t    PLLI2SCFGR;     // RCC PLLI2S configuration register
    __IO    uint32_t    PLLSAICFGR;     // RCC PLL configuration register
    __IO    uint32_t    DCKCFGR;        // RCC Dedicated Clock Configuration Register 
}RCC_TypeDef;


	AHB1ENR = AHB1 + RCC + 0x30 = 0x4002 3800 + 0x30 = 0x40023830

*/

#define				RCC_AHB1ENR				(*((volatile unsigned int *)0x40023830))
#define				GPIOI_MODER				(*((volatile unsigned int *)0x40021C00))				
#define				GPIOI_ODR				(*((volatile unsigned int *)0x40021C14))				


class Led{
	private:
		int diameter;
		float voltage;
		float current;
	public:
		/*Accessors*/
		int getDiameter(){
			return diameter;
		}
		float getVoltage(){
			return voltage;
		}
		float getCurrent(){
			return current;
		}
		/*Mutators*/
		void setDiameter(int d){
			if(d > 0){
				diameter = d;
			}
			else diameter = 0;
		}
		void setVoltage(float v){
			voltage = v;
		}
		void setCurrent(float i){
			current = i;
		}
		/*Methods*/
		Led(){
			diameter = 3;
			voltage = 3.3;
			current = 200;
		}
		Led(int d, float v, float i){
			setDiameter(d);
			setVoltage(v);
			setCurrent(i);
		}
		float power(){
			return (voltage*current);
		}
};


int main(void){
	Led RedLed, GreenLed(5, 3.3, 0.2);
	Led *GreenLed_p;
	
	/*Initialize GreenLed_p*/
	GreenLed_p = &GreenLed;
//	GreenLed_p->setDiameter(5);
//	GreenLed_p->setCurrent(0.8);
//	GreenLed_p->setVoltage(3.3);
	
	/**/
	printf("GreenLed Lower: %f\r\n", GreenLed_p->power());
		
	while(1){
	}
}
