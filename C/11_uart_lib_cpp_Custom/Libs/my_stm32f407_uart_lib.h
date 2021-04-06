#ifndef __MY_STM32F407_UART_LIB_H
#define __MY_STM32F407_UART_LIB_H

#include "my_stm32f407_uart_drivers.h"

/*UART_CommType*/
#ifndef UART_CommType
typedef enum{
	RX_ONLY = 0,
	TX_ONLY,
	RX_AND_TX
}UART_CommType;
#endif // UART_CommType

/*UART_CommType*/
#ifndef UART_CommType
typedef enum{
	_115200 = 0,
	_9600,
}UART_BaudrateType;
#endif // UART_CommType

/**
* Classes
*/

/**/
class UARTcomm{
	private:
		UART_CommType commtype;
		UART_BaudrateType baudrate;
	public:
		UARTcomm(UART_CommType commtype, UART_BaudrateType baudrate);
		void Write(int ch);
		char Read()const;
		UART_BaudrateType getBaudrate()const;
		UART_CommType getCommtype()const;		
};




#endif // __MY_STM32F407_UART_LIB_H


