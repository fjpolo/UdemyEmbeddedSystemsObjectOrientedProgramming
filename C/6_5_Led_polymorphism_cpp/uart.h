#ifndef  __UART_H
#define  __UART_H


#include "stm32f4xx.h"                  // Device header
#include <stdio.h>


#define CR_		0x0D   //"\r"
#define LF_   0x0A   //"\n"  


void USART2_Init(void);
void test_setup(void);

void print_string(char s[]);


int  uart_outdec(unsigned long n);
void uart_outcrfl(void);

#endif