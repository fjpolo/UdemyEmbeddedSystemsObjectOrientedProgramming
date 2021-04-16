#pragma once

/*mcal_reg*/
#include <stddef.h>
#include "mcal_reg.h"
#include <stddef.h>


/**
* Typedefs
*/

/*I2CRegister_t*/
using I2CRegister_t = std::uint32_t volatile;
/*I2CModule_t*/

/**
* \class I2C
*
* \brief
*/
#pragma pack(push, 1)
class I2C_c{
	private:
		/*Attributes*/
		I2CRegister_t CR1;
		I2CRegister_t CR2;
		I2CRegister_t OAR1;
		I2CRegister_t OAR2;
		I2CRegister_t DR;
		I2CRegister_t SR1;
		I2CRegister_t SR2;
		I2CRegister_t CCR;
		I2CRegister_t TRISE;
		I2CRegister_t FLTR;
	
	public:
		/*Attributes*/
		enum I2CModule : std::uint8_t{
			I2C1 = 0,
			I2C2,
			I2C3
		};		
		I2CModule module;
		/*Methods*/
		I2C_c() = default;
		I2C_c(I2CModule _module);
		~I2C_c();
		void *operator new(std::size_t size, I2CModule _module){
			auto address = mcal::reg::i2c_base + (_module * mcal::reg::i2c_offset);
			return reinterpret_cast<void *>(address);
		}
		void Enable();
		void Disable();
		void Init();	
		int ByteWrite(char SlaveAddress, char MemoryLocation, char Data);
		int BurstRead(char SlaveAddress, char MemoryLocation, int n, char *Data);
		
};
#pragma pack(pop)


