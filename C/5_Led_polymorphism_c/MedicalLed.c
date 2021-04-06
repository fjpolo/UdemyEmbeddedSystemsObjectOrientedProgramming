#include "MedicalLed.h"
#include "uart.h"

 void MedicalLed_ctor(MedicalLed_Type * const me,
											 LedWavelength_Type _wavelength,
											LedColor_Type   _color,
											LedState_Type _state)
 {
	 
	 static const struct LedVtable vtable={
	 
	   (void(*)(Led_Type const * const m))&MedicalLed_runDiagnostics,
		 (uint32_t(*)(Led_Type const * const m))&MedicalLed_computeEfficiency
	 };
	 
	 Led_ctor(&me->super,_color,_state);
	 
	 
	 me->super.vptr = &vtable;
	 
	 me->wavelength = _wavelength;
	 
 }
 
 LedWavelength_Type MedicalLed_getWavelength(MedicalLed_Type * const me){
    return (me->wavelength);
 }
 void  MedicalLed_setWavelength(MedicalLed_Type * const me,LedWavelength_Type wavelength){
 
	  me->wavelength = wavelength;
 }
 
 
 uint32_t  MedicalLed_computeEfficiency(MedicalLed_Type const * const me){
 
	 /*Dummy efficiency computation*/
	 
	 const int8_t input = 120;
	 const int8_t output = 86;
	 const int8_t k1 =4;
	 const int8_t k2 = 6;
	 
	 int8_t K;
	 
	 /*if wavelength ==IR K=4 else K=6 */
	 K =  me->wavelength == INFRARED ? k1 : k2;
	 
	 int8_t eff = ((input/output)*100)-K;
	 
	 
	 printf("Medical LED module efficiency is :  %d....\n\r",eff);
	 
	 return eff;
	 
	 
	 
 }
 
 
 
 
 void MedicalLed_runDiagnostics(MedicalLed_Type const *const me){
 
   /*Dummy diagnostics sequence*/
   
	 for(int i=0;i<20;i++){
	 
		 printf("Medical LED Diagnostis stage: %d....\n\r",i);
		 
		 //Do something....
	 
	 
	 }
	 
 }
 
 
 
 
 
