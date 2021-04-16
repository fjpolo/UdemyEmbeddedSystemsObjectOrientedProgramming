#pragma once

namespace mcal{
    namespace reg{
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
    } // END Namespace reg
} // END Namespace mcal


