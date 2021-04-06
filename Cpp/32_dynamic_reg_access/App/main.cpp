#include "mcal_reg.h"




/**
* reg_access_dynamic
*/
template<typename register_addess_type,
				 typename register_value_type>

class reg_access_dynamic{
	public:
		static void reg_get(register_addess_type addr, register_value_type val){
			return (*reinterpret_cast<volatile register_addess_type *>(addr));
		}
		static void reg_set(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) = static_cast<register_value_type>(val); 
		}
		static void reg_or(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) |= static_cast<register_value_type>(val); 
		} 
		static void reg_and(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(val); 
		}
		static void reg_not(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(~val); 
		}
		static void bit_set(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) |= static_cast<register_value_type>(1U<<val); 
		}
		static void bit_clear(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(~static_cast<register_value_type>(1U<<val)); 
		}
		static void bit_not(register_addess_type addr, register_value_type val){
			*reinterpret_cast<volatile register_addess_type *>(addr) ^= static_cast<register_value_type>(1U<<val); 
		}
		static void bit_get(register_addess_type addr, register_value_type val){
			return ( (reg_get(addr) & static_cast<register_value_type>(1U<<val)) != static_cast<register_value_type>(0U) );
		}
		
};






int main(void){
	
	/*Enable clock access PORT I*/
	reg_access_dynamic<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::rcc::ahb1enr, (1U<<8)); 
	
	/*Set first 8 pins  of GPIO I high*/
	reg_access_dynamic<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::gpio::cfg_regs::gpioi_cfg::gpiog_odr, (0xFF));
	

	while(1){
			/*Toggle Pin 7 - Red LED*/
			reg_access_dynamic<std::uint32_t, std::uint32_t>::bit_not(mcal::reg::gpio::cfg_regs::gpioi_cfg::gpiog_odr, (7));
		for(int i=0;i<1000;i++){}
	}
}

