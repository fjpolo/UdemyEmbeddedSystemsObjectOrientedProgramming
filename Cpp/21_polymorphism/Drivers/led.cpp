#include "led.h"

/**
* Led Class
*/
//void Led::getType(){
//	printf("General LED\r\n");
//}
//void Led::ledState(){
//	printf("General LED ON\r\n");
//}


/**
* MedicalLed Class
*/
void MedicalLed::getType(){
	printf("Medical LED\r\n");
}
void MedicalLed::ledState(){
	printf("Medical LED scannig\r\n");
}


/**
* DisplayLed Class
*/
void DisplayLed::getType(){
	printf("Display LED\r\n");
}
void DisplayLed::ledState(){
	printf("Display LED displaying\r\n");
}

