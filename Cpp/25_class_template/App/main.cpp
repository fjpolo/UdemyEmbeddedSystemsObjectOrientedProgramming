#include "mcal_reg.h"
#include "uartBSP.h"
//#include <iostream>	// adds 26k flash!!!!!!
#include <stdio.h>
#include "led.h"

#define ARRAY_SIZE	7 

template <class T>
class dataStatistics{
	private:
		T data[ARRAY_SIZE];
		int capacity;
	public:
		dataStatistics();
		dataStatistics(T d[]){
			for(int i=0;i<ARRAY_SIZE;i++){
				data[i] = d[i];
			}			
		}
		float computeMean();
		T findMax();
		int searchValue(T val);
		T findMode();
};

template <class T>
float dataStatistics<T>::computeMean(){
	return 0;
}

template <class T>
T dataStatistics<T>::findMax(){
	T Max = data[0];
	for(int i=1;i<ARRAY_SIZE;i++){
		if(data[i] > Max) Max = data[i];
	}
	return Max;
}

template <class T>
int dataStatistics<T>::searchValue(T val){
	return 0;
}

template <class T>
T dataStatistics<T>::findMode(){
	return 0;
}

int main(void){
	USART6_Init();

	float f_values[ARRAY_SIZE] = {0.1, 0.9, 0.2, 0.14, 0.15, 0.99, 0.56};
	int i_values[ARRAY_SIZE] = {1, 6, 7, 4, 5,3, 9};
	
	dataStatistics<float> fData(f_values);
	dataStatistics<int> iData(i_values);
	
	printf("Float Max: %f\r\n", fData.findMax());
	printf("Integer Max: %d\r\n", iData.findMax());
	
	
	while(1){
	}
}


