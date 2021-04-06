#ifndef __MEDICALLED_H
#define __MEDICALLED_H

#include "Led.h"

/*LedWavelength_Type*/
#ifndef LedWavelength_Type
typedef enum{
	INFRARED = 910,			// nm
	NEAR_INFRARED = 880
}LedWavelength_Type;
#endif // LedWavelength_Type

/*MedicalLed_Type*/
#ifndef MedicalLed_Type
typedef struct{
	Led_Type						super;
	LedWavelength_Type	wavelength;
}MedicalLed_Type;
#endif // MedicalLed_Type

/**
*
*/
void MedicalLed_ctor(MedicalLed_Type * const me, 
										 LedWavelength_Type _wavelength,
										 LedColor_Type _color,
										 LedState_Type _state
										);
LedWavelength_Type MedicalLed_getWavelength(MedicalLed_Type * const me);
void MedicalLed_setWavelength(MedicalLed_Type * const me, LedWavelength_Type _wavelength);
/*Virtual functions*/
void MedicalLed_runDiagnostics(MedicalLed_Type const * const me);
uint32_t MedicalLed_computeEfficiency(MedicalLed_Type const * const me);

#endif	//__MEDICALLED_H
