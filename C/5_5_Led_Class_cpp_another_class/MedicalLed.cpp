#include "MedicalLed.h"




MedicalLed::MedicalLed( LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state)

:Led(_color,_state),
wavelength(_wavelength)
{
	
}

	
LedWavelength_Type MedicalLed:: MedicalLed_getWavelength(){
	
	return (this->wavelength);
}
 void  MedicalLed:: MedicalLed_setWavelength(LedWavelength_Type wavelength){
 
	  this->wavelength =  wavelength;
 
 }