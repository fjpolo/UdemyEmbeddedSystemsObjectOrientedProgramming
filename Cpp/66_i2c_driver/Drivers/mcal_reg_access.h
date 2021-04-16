#pragma once

namespace mcal{
    namespace reg{
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
    } // END Namespaca reg
} // END Namespace mcal

