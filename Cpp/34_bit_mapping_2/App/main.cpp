#include "mcal_reg.h"




/**
* reg_access
*/
//template<typename register_addess_type,
//				 typename register_value_type>

//class reg_access_dynamic{
//	public:
//		static void reg_get(register_addess_type addr, register_value_type val){
//			return (*reinterpret_cast<volatile register_addess_type *>(addr));
//		}
//		static void reg_set(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) = static_cast<register_value_type>(val); 
//		}
//		static void reg_or(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) |= static_cast<register_value_type>(val); 
//		} 
//		static void reg_and(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(val); 
//		}
//		static void reg_not(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(~val); 
//		}
//		static void bit_set(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) |= static_cast<register_value_type>(1U<<val); 
//		}
//		static void bit_clear(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) &= static_cast<register_value_type>(~static_cast<register_value_type>(1U<<val)); 
//		}
//		static void bit_not(register_addess_type addr, register_value_type val){
//			*reinterpret_cast<volatile register_addess_type *>(addr) ^= static_cast<register_value_type>(1U<<val); 
//		}
//		static void bit_get(register_addess_type addr, register_value_type val){
//			return ( (reg_get(addr) & static_cast<register_value_type>(1U<<val)) != static_cast<register_value_type>(0U) );
//		}
//		
//};






int main(void){
	std::uint32_t abh1enr = mcal::reg::rcc::ahb1enr;
	std::uint32_t gpioi = mcal::reg::gpio::cfg_regs::gpioi_cfg::gpiog_odr;
	
	/*Enable clock access PORT I*/
	reinterpret_cast<volatile reg_map_c *>(abh1enr)->bits.b8 = 1U;
	
	/*Turn 8 first pins on*/
	reinterpret_cast<volatile reg_map_c *>(gpioi)->value = 0xFF;
	
	while(1){
			/*Toggle Pin 7 - Red LED*/
			reinterpret_cast<volatile reg_map_c *>(gpioi)->bits.b7 ^= 1U;
			for(int i=0;i<1000;i++){}
	}
}

