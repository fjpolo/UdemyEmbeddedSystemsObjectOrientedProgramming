#include "mcal_reg.h"




/**
* reg_access
*/
template<typename addr_type,
				 typename reg_type,
				 const addr_type addr,
				 const reg_type val>

class reg_access{
	public:
		static reg_type reg_get(){
			return (*reinterpret_cast<volatile addr_type *>(addr));
		}
		static void reg_set(){
			*reinterpret_cast<volatile addr_type *>(addr) = static_cast<reg_type>(val); 
		}
		static void reg_or(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(val); 
		} 
		static void reg_and(){
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(val); 
		}
		static void reg_not(){
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~val); 
		}
		static void bit_set(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<val); 
		}
		static void bit_clear(){
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~static_cast<reg_type>(1U<<val)); 
		}
		static void bit_not(){
			*reinterpret_cast<volatile addr_type *>(addr) ^= static_cast<reg_type>(1U<<val); 
		}
		static void bit_get(){
			return ( (reg_get(addr) & static_cast<reg_type>(1U<<val)) != static_cast<reg_type>(0U) );
		}
		
};






int main(void){
	
	/*Enable clock access PORT I*/
	reg_access<std::uint32_t,
						 std::uint32_t,
						 mcal::reg::rcc::ahb1enr,
						(1U<<8)
						>::reg_or(); 
	
	/*Set first 8 pins  of GPIO I high*/
	reg_access<std::uint32_t,
						 std::uint32_t,
	mcal::reg::gpio::cfg_regs::gpioi_cfg::gpiog_odr,
						(0xFF)
						>::reg_set();
	

	while(1){
			/*Toggle Pin 7 - Red LED*/
			reg_access<std::uint32_t,
									std::uint32_t,
									mcal::reg::gpio::cfg_regs::gpioi_cfg::gpiog_odr,
									(7)
								>::bit_not();
		for(int i=0;i<1000;i++){}
	}
}

