#include "DS1307.h"

namespace{
	/**/
	static 	bool InitI2C(I2C_c &i2c){
		i2c.Init();
		return true;
	}

}

namespace DS1307{
	/*InitRTC*/
	void InitRTC(I2C_c &i2c){
		/**
		 * SCL = PB8
		 * SDA = PB9
		 */
		
		// Enable GPIOB clock
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::ahb1enr,
													(1U<<0)
												 >::reg_or();
		
		// Enable I2C1 clock
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::apb1enr,
													(1U<<1)
												 >::reg_or();
		
		// PB8 alt func
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_moder,
													(1U<<16)
												 >::reg_not();
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_moder,
													(1U<<17)
												 >::reg_or();
		
		// PB9 alt func
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_moder,
													(1U<<18)
												 >::reg_not();
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_moder,
													(1U<<19)
												 >::reg_or();
		// Set PB8, PB9 to i2c alternate function
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_afrh,
													(0xFF)
												 >::reg_not();
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_afrh,
													(0x44)
												 >::reg_or();
		
		// Set output type to open drain
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_otyper,
													(0x300)
												 >::reg_or();
		
		// Set pins to pull-up
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_pupdr,
													(0xF0000)
												 >::reg_not();
		mcal::reg::reg_access<
													std::uint32_t,
													std::uint32_t,
													mcal::reg::gpiob_pupdr,
													(0x50000)
												 >::reg_not();

		/*I2C configuration*/
		i2c.Init();
		
	}
		bool GetStatus(I2C_c &i2c){
			char statusReg[15];
			i2c.BurstRead(DS1307_SLAVE_ADDRESS, 0, 7, statusReg);
			return statusReg[0] & 0x01 ; 
		}
}