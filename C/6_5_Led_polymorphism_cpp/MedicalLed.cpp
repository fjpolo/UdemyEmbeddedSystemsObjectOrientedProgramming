#include "MedicalLed.h"
#include "uart.h"



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
 
 
 char effi_m[] = {'M','e','d','_','E','F','F','.','.','.'};
 
 uint32_t  MedicalLed::compute_efficiency() const{
 
    //Dummy efficeincy computation
	 
	 const int8_t input = 120;
	 const int8_t output =86;
	 const int8_t k1 =4;
	 const int8_t k2 =6;
	 int8_t K;
	 K = this->wavelength == INFRARED ? k1 : k2;
	 
	 int8_t eff =  ((input/output)*100)-K;
	 
	 
	 uart_outcrfl();
	 print_string(effi_m);
	 uart_outdec(eff);
	 uart_outcrfl();

	 
	 return eff;
 }
 
 
 char medl[] = {'M','e','d','_','L','E','D','.','.','.'};

 
 void MedicalLed:: run_diagnostics() const {
 
   //Dummy diagnostics sequence
	 for(int i=0;i<20;i++){
	 
	 
	    //Do somthing....
		 
	 uart_outcrfl();
	 print_string(medl);
	 uart_outdec(i);
	 uart_outcrfl();

	 }
 
 }