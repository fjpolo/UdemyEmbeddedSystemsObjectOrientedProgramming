#include "uart.h"
#include "stdio.h"
#include "systick.h"
#include "tim2.h"
#include "DS1307.h"

char dataFromRT[15];


int main(void){		
	int SysTickFlag;

	
	/*Init USART6*/
	uart6_init();
	/*I2C1*/
	I2C_c &i2c1 = * new (I2C_c::I2CModule::I2C1) I2C_c;
	/*DS1307*/
	DS1307::InitRTC(i2c1);
	/*Enable clock for GPIOA*/
	mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::ahb1enr,
													(0x01)
												 >::reg_or();
	/*Set PA5 to output*/
	mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpioa_moder,
													(1U<<10)
												 >::reg_or();
											 
	
	
	
	
	/*Superloop*/
	while(true){
		bool DS1307Status;
		DS1307Status = DS1307::GetStatus(i2c1);
		if(DS1307Status){
			/*PA5 LED on*/
			mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpioa_odr,
													(1U<<5)
												 >::reg_or();
		}
		else{
			/*PA5 LED off*/
			mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpioa_odr,
													(1U<<5)
												 >::reg_not();
		}
		
		/*Wait for a bit*/
		for(int i=0; i<10000;++i){}
	}
}
