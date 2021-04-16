#include "i2c.h"

/*I2C_c::I2C_c*/
I2C_c::I2C_c(I2CModule _module)
:module(_module)
{
}
/*I2C_c::~I2C_c*/
I2C_c::~I2C_c(){
	
}
/*I2C::Enable*/
void I2C_c::Enable(){
	/*Enable*/
	this->CR1 |= (1U)<<0;
}
/*I2C_c::Disable*/
void I2C_c::Disable(){
	/*Disable*/
	this->CR1 &= ~(1U)<<0;
}	
/*I2C_c::Init*/
void I2C_c::Init(){
		// Disable
		this->Disable();
	
		/*Configure*/
	
		//Sw reset I2C
		this->CR1 = 0x8000;
		// Out of reset
		this->CR1 &= ~0x8000;
		//Peripheral clock 16MHz
		this->CR2 = 0x0010;
		// Standard mode, 100kHz clock
		this->CCR = 80;
		//Set maximum rise time
		this->TRISE = 17;
		// Enable module
		this->Enable();
}	
/*I2C_c::ByteWrite*/
int I2C_c::ByteWrite(char SlaveAddress, char MemoryLocation, char Data){
	volatile int tmp;
	
	//Wait while busy
	while(this->SR2 & 0x02);
	//Generate start
	this->CR1 |= 0x100;
	//Wait until start flag is set
	while(this->SR1 & 0x01);
	// Transmit slave address
	this->DR = SlaveAddress<<1;
	//Wait until address flag is set
	while(this->SR1 & 0x02);
	// Clear address flag
	tmp = this->SR1;
	// Wait until data register empty
	while(!(this->SR1 & 0x80));
	// Send memory address
	this->DR = MemoryLocation;
	// Wait until data register empty
	while(!(this->SR1 & 0x80));
	//Send data byte
	this->DR = Data;
	//Wait until transfer is finished
	while(!(this->SR1 & 0x04));
	//Generate stop condition
	this->CR1 |= 0x200;
	
	
	return 0;
}
		
/*I2C_c::BurstRead*/
int I2C_c::BurstRead(char SlaveAddress, char MemoryLocation, int n, char *Data){
	volatile int tmp;
	
	// Wait until bus not busy
	while(this->SR2 & 0x02);
	//Disable pos
	this->CR1 &= ~0x800;
	//Generate start
	this->CR1 |= 0x100;
	//Wait until start flag is set
	while(this->SR1 & 0x01);
	// Transmit slave address
	this->DR = SlaveAddress;
	//Wait until address flag is set
	while(this->SR1 & 0x02);
	// Clear address flag
	tmp = this->SR1;
	//Wait until Tx empty
	while(this->SR1 & 0x80);
	// Send memory address
	this->DR = MemoryLocation;
	//Wait until Tx empty
	while(this->SR1 & 0x80);
	//Generate restart
	this->CR1 |= 0x01;
	//Wait until start flag is set
	while(this->SR1 & 1);
	//Transmit slave address + read
	this->DR = SlaveAddress<<1 | 1;
	//Wait until address flag is set
	while(this->SR1 & 2);
	// Clear address flag
	tmp = this->SR1;
	//Enable ACK
	this->CR1 |= 0x0400;
	// Receive
	while(n > 0U){
		// One byte left
		if(n == 1U){
			//Disable ACK
			this->CR1 &= ~0x0400;
			//Generate Stop
			this->CR1 |= 0x200;
			//Wait RXNE flag set
			while(!(this->SR1 & 0x40));
			// Read data
			*Data++ = this->DR;
		}
		// More than 1 byte left
		else{
			// Wait for RXNE flag
			while(!(this->SR1 & 0x40));
			// Read data
			*Data++ = this->DR;
			// Decrement n
			--n;
		}
	}
	
	
	return 0;
}
