#include "led.h"

/**
* Led Class
*/
int Led::TotalLedCount = 0;

Led::Led(){
	this->TotalLedCount++;
}

