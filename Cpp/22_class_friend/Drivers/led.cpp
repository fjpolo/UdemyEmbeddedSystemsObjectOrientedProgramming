#include "led.h"

void CarLamp::setCarLamp(){
			mLed.current = 0.8;
			mLed.voltage = 3.3;
			mLed.nrOfPins = 6;
			mLed.diameter = 0.5;
			/**/
			printf("Power of CarLamp: %f\r\n", (mLed.voltage * mLed.current));
		}
