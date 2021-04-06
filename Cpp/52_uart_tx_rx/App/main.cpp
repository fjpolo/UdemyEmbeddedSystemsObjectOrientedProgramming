#include "mcal_reg.h"

// Button at PB1

void usart6_write(int ch){
	std::uint32_t _ch = ch + 0xFF;
	// Wait for Tx buffer
	while( !(mcal::reg::UART6->SR & 0x0080U) ){}
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
}

char uart6_read(void){
	static char rcv_ch;
	// Wait for char to arrive
	while( !(mcal::reg::UART6->SR & 0x0020U) ){}
	rcv_ch =  	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t,
												mcal::reg::uart6_dr, 
												0U
											 >::reg_get();
	return rcv_ch;
}

/** @program: Driver to control LED at PI7 using PB1 button*/
std::int32_t button_state;

int main(void){
	static char msgChar;
	
	/* 1. Enable clock access to GPIOB */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<1U)
											 >::reg_or();
	
	/* 2. Enable clock access to GPIOI */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::ahb1enr,
												(1U<<8U)
											 >::reg_or();
	
	/* 3. Set PB1 as input */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiob_moder,
												(1U<<(2*1U))								// Pin 1
											 >::reg_or();
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpiob_moder,
												(1U<<((2*1U)+1U))						// Pin 1
											 >::reg_or();
											 
	/* 4. Set PI7 as output */
	mcal::reg::reg_access<std::uint32_t, 
												std::uint32_t, 
												mcal::reg::gpioi_moder,
												(0U<<(2*7U))						// Pin 7
											 >::reg_or();
											 
											 
											 
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
	usart6_write('\n');
	
	/*Superloop*/
	while(true){
		
//		/* 5. Read PB1*/
//		button_state = mcal::reg::reg_access<std::uint32_t, 
//																				 std::uint32_t,
//																				 mcal::reg::gpiob_idr,
//																				 0U
//																				>::reg_get();
//		if(button_state & 0x02){
//			usart6_write('Y');
//			/* 6. Toggle PI7 */
//			mcal::reg::reg_access<std::uint32_t, 
//														std::uint32_t, 
//														mcal::reg::gpioi_bssr,
//														(1U<<7U)						// Pin 7 set
//														>::reg_set();	
//		}
//		else{
//			usart6_write('N');
//			mcal::reg::reg_access<std::uint32_t, 
//														std::uint32_t, 
//														mcal::reg::gpioi_bssr,
//														(1U<<23U)						// Pin 7 reset
//														>::reg_set();	
//		}

	msgChar = uart6_read();
	usart6_write(msgChar);

	}	
}
