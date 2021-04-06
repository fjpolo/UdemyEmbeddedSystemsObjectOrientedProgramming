#ifndef _MEDICALLED_H
#define _MEDICALLED_H

#include "led.h"

typedef enum{

	INFRARED	    = 910,
	NEAR_INFRARED = 880

}LedWavelength_Type;


typedef struct{

	Led_Type super;
	LedWavelength_Type wavelength;  
	

}MedicalLed_Type;


  void MedicalLed_ctor(MedicalLed_Type * const me,
											 LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state);

	
 LedWavelength_Type MedicalLed_getWavelength(MedicalLed_Type * const me);
 void  MedicalLed_setWavelength(MedicalLed_Type * const me,LedWavelength_Type wavelength);

	
	uint32_t MedicalLed_computeEfficiency( MedicalLed_Type const * const me);
	void   MedicalLed_runDiagnostics(MedicalLed_Type  const * const me);
	
	
	
#endif