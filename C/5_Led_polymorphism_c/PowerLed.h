#ifndef	_POWERLED_H
#define _POWERLED_H

#include "led.h"

typedef uint8_t led_elec_type;
typedef uint8_t led_dim_type;


typedef  enum{
	CURR_LOW				= 10,   /*10mA*/
	CURR_NORMAL 		= 20,
	CURR_HIGH				= 35,
	CURR_VERY_HIGH 	= 60


}LedCurrent_Type;

typedef enum{
	DIAM_2MM = 2,  /*2mm*/
	DIAM_5MM = 5,
	DIAM_7MM = 7

}LedDiamter_Type;

typedef enum{
  VOL_LOW    = 3, /*3 volts*/
	VOL_NORMAL = 5,
	VOL_HIGH	 = 9
	
}LedVoltage_Type;


typedef struct{
	Led_Type 		super; 
	LedDiamter_Type  diameter;
	LedCurrent_Type  current;
	LedVoltage_Type  voltage;

}PowerLed_Type;


void PowerLed_ctor(PowerLed_Type * const me,
									 LedColor_Type   _color,
									 LedState_Type	_state,
									 LedDiamter_Type  _diameter,
									 LedCurrent_Type   _current,
									 LedVoltage_Type  _voltage);


void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type  _current );
void PowerLed_setDiameter(PowerLed_Type * const me, LedDiamter_Type _diameter);
void PowerLed_setVoltage(PowerLed_Type *const me, LedVoltage_Type _voltage);
led_elec_type PowerLed_computePower(PowerLed_Type * const me);
led_elec_type PowerLed_getCurrent(PowerLed_Type * const me);
led_elec_type PowerLed_getDiameter(PowerLed_Type * const me);
led_elec_type PowerLed_getVoltage(PowerLed_Type * const me);



	uint32_t PowerLed_computeEfficiency( PowerLed_Type const * const me);
	void   PowerLed_runDiagnostics(PowerLed_Type  const * const me);





#endif