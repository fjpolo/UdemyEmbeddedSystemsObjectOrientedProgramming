#ifndef __MCAL_REG_H
#define __MCAL_REG_H

#include <cstdint>

namespace mcal{
	namespace reg{
		/*Base registers*/
		const std::uint32_t periph_base				= 0x40000000;
		const std::uint32_t	ahb1_periph_base 	= periph_base + 0x200000U;
		const std::uint32_t rcc_base 					= periph_base + 0x3800;
		/*RCC Registers*/
		namespace rcc{
			const std::uint32_t ahb1enr					= rcc_base + 0x0030U;
			const std::uint32_t ahb2enr					= rcc_base + 0x0034U;
			const std::uint32_t ahb3enr					= rcc_base + 0x0038U;
		} // END Namespace RCC
		/*GPIO Registers*/
		namespace gpio{
			/*GPIO Base*/
			const std::uint32_t gpioa						= ahb1_periph_base + 0x0030U;
			const std::uint32_t gpiob						= ahb1_periph_base + 0x0400U;
			const std::uint32_t gpioc						= ahb1_periph_base + 0x0800U;
			const std::uint32_t gpiod						= ahb1_periph_base + 0x0C00U;
			const std::uint32_t gpioe						= ahb1_periph_base + 0x1000U;
			const std::uint32_t gpiof						= ahb1_periph_base + 0x1400U;
			const std::uint32_t gpiog						= ahb1_periph_base + 0x1800U;
			const std::uint32_t gpioh						= ahb1_periph_base + 0x1C00U;
			const std::uint32_t gpioi						= ahb1_periph_base + 0x2000U;
			/*Config registers*/
			namespace cfg_regs{
				const std::uint32_t moder_offset	= 0x0000U;
				const std::uint32_t idr_offset		= 0x0010U;
				const std::uint32_t odr_offset		= 0x0014U;
				const std::uint32_t barr_offset		= 0x0018U;
				/*GPIOI config registers*/
				namespace gpiob_cfg{
					const std::uint32_t gpiob_moder	= gpiob + moder_offset;
					const std::uint32_t gpiob_idr		= gpiob + idr_offset;
					const std::uint32_t gpiob_odr		= gpiob + odr_offset;
					const std::uint32_t gpiob_barr	= gpiob + barr_offset;
				} // END Namespace gpioi_cfg
				/*GPIOI config registers*/
				namespace gpioi_cfg{
					const std::uint32_t gpiog_moder	= gpiog + moder_offset;
					const std::uint32_t gpiog_idr		= gpiog + idr_offset;
					const std::uint32_t gpiog_odr		= gpiog + odr_offset;
					const std::uint32_t gpiog_barr	= gpiog + barr_offset;
				} // END Namespace gpioi_cfg
				/*GPIOI config registers*/
				namespace gpioi_cfg{
					const std::uint32_t gpioi_moder	= gpioi + moder_offset;
					const std::uint32_t gpioi_idr		= gpioi + idr_offset;
					const std::uint32_t gpioi_odr		= gpioi + odr_offset;
					const std::uint32_t gpioi_barr	= gpioi + barr_offset;
				} // END Namespace gpioi_cfg
			} // END Namespace cfg_regs
		} // END Namespace RCC		
	} // END Nampespace reg
} // END Nampespace mcal


/**
* bit32_type
*/
#ifndef bit32_type 
typedef struct bit32_type{
	std::uint8_t b0 : 1;
	std::uint8_t b1 : 1;
	std::uint8_t b2 : 1;
	std::uint8_t b3 : 1;
	std::uint8_t b4 : 1;
	std::uint8_t b5 : 1;
	std::uint8_t b6 : 1;
	std::uint8_t b7 : 1;

	std::uint8_t b8 : 1;
	std::uint8_t b9 : 1;
	std::uint8_t b10 : 1;
	std::uint8_t b11 : 1;
	std::uint8_t b12 : 1;
	std::uint8_t b13 : 1;
	std::uint8_t b14 : 1;
	std::uint8_t b15 : 1;
	
	std::uint8_t b16 : 1;
	std::uint8_t b17 : 1;
	std::uint8_t b18 : 1;
	std::uint8_t b19 : 1;
	std::uint8_t b20 : 1;
	std::uint8_t b21 : 1;
	std::uint8_t b22 : 1;
	std::uint8_t b23 : 1;
	
	std::uint8_t b24 : 1;
	std::uint8_t b25 : 1;
	std::uint8_t b26 : 1;
	std::uint8_t b27 : 1;
	std::uint8_t b28 : 1;
	std::uint8_t b29 : 1;
	std::uint8_t b30 : 1;
	std::uint8_t b31 : 1;	
}bit32_type;
#endif // bit32_type

#endif // __MCAL_REG_H

