#include <stdio.h>
#include "uart.h"
#include "mcal_reg.h"

/**
* https://www.keil.com/support/man/docs/armlib/armlib_chr1358938931411.htm
*/

//		USART_TypeDef *	UART6 =  ((USART_TypeDef*)mcal::reg::uart6_base);
#define UART6 	  ((mcal::reg::USART_TypeDef*)mcal::reg::uart6_base)


void uart6_init(){
		/**
	* USART6 -> Tx = PG14 ; Rx = PC7
	*/
	// 1. Enable clock to GPIOC and GPIOG
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<2)
											 >::reg_or();
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<6)
											 >::reg_or();
											 
	// 2. Enable rcc to  APB2
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::apb2enr,
												(1U<<5)
											 >::reg_or();
											 
	// 3. Configure PC7 and PG14 as alternate functions
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioc_moder,
												(1U<<(2*2U))										// Pin 7
											 >::reg_or();
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioc_moder,
												(0U<<((2*2U)+1))								// Pin 7
											 >::reg_or();	
	
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiog_moder,
												(1U<<(2*6U))										// Pin 14
											 >::reg_or();
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiog_moder,
												(0U<<((2*6U)+1))								// Pin 14
											 >::reg_or();	
	
	// 4. Set ALT type to UART 6
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioc_afrl,
												(0x80000000U)								// AF8 @ Rx PC7
											 >::reg_or();	
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiog_afrh,
												(0x8000000U)								// AF8 @ Tx PG14
											 >::reg_or();
	
	// 5. Configure USART to 9600bps @ 16MHz
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::uart6_brr,
												(0x0683U)								
											 >::reg_set();
	
	
	// 6. Enable Tx, 8-bit
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::uart6_cr1,
												(0x0008U)								
											 >::reg_set();
	
	// 7. Set 1 stop bit
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::uart6_cr2,
												(0x0000U)								
											 >::reg_set();
											 
	// 8. Disable flow control
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::uart6_cr3,
												(0x0000U)								
											 >::reg_set();
	// 9. Enale UART
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::uart6_cr1,
												(0x2000U)								
											 >::reg_or();
	
	
	/**
	* END USART6
	*/
}

int usart6_write(int ch){
	std::uint32_t _ch = ch + 0xFF;
	// Wait for Tx buffer
	while( !(UART6->SR & 0x0080U) ){}
	// Send		
	//mcal::reg::UART6->DR = _ch;	
//	mcal::reg::reg_access<std::uint32_t, 
//												std::uint32_t,
//												mcal::reg::uart6_dr, 
//												_ch
//											 >::reg_set();
		mcal::reg::reg_access_dynamic<std::uint32_t, 
													std::uint32_t
												>::reg_set(mcal::reg::uart6_dr, 
																	 _ch);
	return 1;
}

int uart6_read(void){
	static char rcv_ch;
	// Wait for char to arrive
	while( !(UART6->SR & 0x0020U) ){}
	rcv_ch =  	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::uart6_dr, 
												0U
											 >::reg_get();
	return rcv_ch;
}

///**
//* Bind console to uart
//*/
//namespace std {
//  struct __FILE
//  {
//    int handle;
//    /* Whatever you require here. If the only file you are using is */
//    /* standard output using printf() for debugging, no file handling */
//    /* is required. */
//  };
//  FILE __stdout;
//  FILE __stdin;
//  FILE __stderr;
//	
//  int fgetc(FILE *f)
//  {
//    /* Your implementation of fgetc(). */
//		int c;
//		c = uart6_read();
//		if(c == '\r'){
//			usart6_write(c);
//			c = '\n';
//		}
//		usart6_write(c);
//    return c;
//  }
//  int fputc(int c, FILE *stream)
//  {
//    /* Your implementation of fputc(). */
//		return usart6_write(c);
//  }
//  int ferror(FILE *stream)
//  {
//    /* Your implementation of ferror(). */
//		return 0;
//  }
//  long int ftell(FILE *stream)
//  {
//    /* Your implementation of ftell(). */
//		return 0;
//  }
//  int fclose(FILE *f)
//  {
//    /* Your implementation of fclose(). */
//    return 0;
//  }
//  int fseek(FILE *f, long nPos, int nMode)
//  {
//    /* Your implementation of fseek(). */
//    return 0;
//  }
//  int fflush(FILE *f)
//  {
//    /* Your implementation of fflush(). */    
//    return 0;
//  }
//}

