#include "MedicalLed.h"

 void MedicalLed_ctor(MedicalLed_Type * const me,
											 LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state)
 {
	 Led_ctor(&me->super,_color,_state);
	 me->wavelength = _wavelength;
	 
 }
 
 LedWavelength_Type MedicalLed_getWavelength(MedicalLed_Type * const me){
    return (me->wavelength);
 }
 void  MedicalLed_setWavelength(MedicalLed_Type * const me,LedWavelength_Type wavelength){
 
	  me->wavelength = wavelength;
 }
