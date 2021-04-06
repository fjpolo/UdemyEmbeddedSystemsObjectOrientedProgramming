#include "MedicalLed.h"

#ifdef __cplusplus
extern "C" {
#endif	//__cplusplus

void MedicalLed_ctor(MedicalLed_Type * const me, LedWavelength_Type _wavelength,LedColor_Type _color,LedState_Type _state){
	/*Virtual table*/
	static const struct LedVtable vtable={
		(void(*)(Led_Type const * const me))&MedicalLed_runDiagnostics,
		(uint32_t(*)(Led_Type const * const me))&MedicalLed_computeEfficiency
	};
	
	/*Parent*/
	Led_ctor(&(me->super), _color, _state);
	me->super.vptr = &vtable;

	/*Child*/
	me->wavelength = _wavelength;
	
	
} // END MedicalLed_ctor

LedWavelength_Type MedicalLed_getWavelength(MedicalLed_Type * const me){
	return me->wavelength;
}// END MedicalLed_getWavelength
	
void MedicalLed_setWavelength(MedicalLed_Type * const me, LedWavelength_Type _wavelength){
	me->wavelength = _wavelength;
} // END MedicalLed_setWavelength


/*Virtual functions*/
void MedicalLed_runDiagnostics(MedicalLed_Type const * const me){
	/**/
	printf("Running medical diagnosis\n");
	/**/
	for(int i=0;i<20;i++){
		printf(".\n");
	}
	/**/
	printf("Done!\n");
}
uint32_t MedicalLed_computeEfficiency(MedicalLed_Type const * const me){
	const int8_t input = 120;
	const int8_t output = 8;
	const int8_t k1 = 4;
	const int8_t k2 = 6;
	int K;
	int eff;

	/*Efficiency*/
	K = (me->wavelength == INFRARED) ? k1 : k2;
	eff = ((input/output) * 100) - K;
	printf("Efficiency = %d\n", eff);
}

#ifdef __cplusplus
}
#endif	//__cplusplus
	
	