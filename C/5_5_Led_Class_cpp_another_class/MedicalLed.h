#ifndef _MEDICALLED_H
#define _MEDICALLED_H

#include "led.h"

typedef enum{

	INFRARED	    = 910,
	NEAR_INFRARED = 880

}LedWavelength_Type;


class MedicalLed : public Led{
	
	
private:	
	
	LedWavelength_Type wavelength;  
	

public:

   MedicalLed( LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state);

	
	LedWavelength_Type MedicalLed_getWavelength();
 void  MedicalLed_setWavelength(LedWavelength_Type wavelength);

};
#endif