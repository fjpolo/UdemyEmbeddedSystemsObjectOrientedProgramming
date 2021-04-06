#include "PowerLed.h"
PowerLed::PowerLed(
									 LedColor_Type   _color,
									 LedState_Type	_state,
									 LedDiamter_Type  _diameter,
									 LedCurrent_Type   _current,
									 LedVoltage_Type  _voltage)
	 :Led(_color,_state),
		diameter(_diameter),
    current(_current),
    voltage(_voltage)
{
										 
}
									 
void PowerLed::PowerLed_setCurrent(LedCurrent_Type  _current ){
	
 this->current = _current;
}

void PowerLed::PowerLed_setDiameter( LedDiamter_Type _diameter){
	
	 this->diameter = _diameter;
}

void PowerLed::PowerLed_setVoltage( LedVoltage_Type _voltage){

  this->voltage = _voltage;
}


led_elec_type PowerLed::PowerLed_computePower(){

  return(this->current * this->voltage);
}


led_elec_type PowerLed::PowerLed_getCurrent(){

   return this->current;
}

led_elec_type PowerLed::PowerLed_getDiameter(){

  return this->diameter;
}


led_elec_type PowerLed::PowerLed_getVoltage(){

 return this->voltage;
}


 char effi_p[] = {'P','o','w','_','E','F','F','.','.','.'};


 uint32_t  PowerLed::compute_efficiency() const{
 
    //Dummy efficeincy computation
	 

	  const int8_t input = 120;
	  const int8_t output = 86;
	 
	 int8_t eff =  ((input/output)*100) -(int8_t)((this->current)/2);
	 
	 	 uart_outcrfl();
	 print_string(effi_p);
	 uart_outdec(eff);
	 uart_outcrfl();

	 
	 return eff;
 }
 
  char powl[] = {'P','o','w','_','L','E','D','.','.','.'};

 void PowerLed:: run_diagnostics() const {
 
   //Dummy diagnostics sequence
	 for(int i=0;i< (int)this->current;i++){
	 
	 
	    //Do somthing....
		 	 uart_outcrfl();
	    print_string(powl);
	    uart_outdec(i);
	     uart_outcrfl();

		
	 }
 
 }
