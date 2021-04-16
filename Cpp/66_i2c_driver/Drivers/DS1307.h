#pragma once

#include "i2c.h"

	#define DS1307_SLAVE_ADDRESS 0x68


namespace DS1307{
	void InitRTC(I2C_c &i2c);
	bool GetStatus(I2C_c &i2c);
	int Read(I2C_c &i2c, char MemoryLocation, int n, char *Data);
	int WriteByte(I2C_c &i2c, char MemoryLocation, char Data);
}