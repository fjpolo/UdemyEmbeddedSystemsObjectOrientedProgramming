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
		static void set_pin_output(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(val*2));
		}
		static void set_pin_input(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(1+(val*2)));
		}
		static void set_pin_analog(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(1+(val*2)));
		}
		static void set_pin_alternate(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(1+(val*2)));
		}
};



/**
*
*/
template <typename addr_type, 
					typename reg_type, 
					const addr_type port, 
					const reg_type bpos>
class port_pin{
	public:
		static void set_direction_output(){
			port_dir_type::set_pin_output();
		}
		static void set_direction_input(){
			port_dir_type::set_pin_input();
		}
		static void set_direction_analog(){
			port_dir_type::set_pin_analog();
		}
		static void set_direction_alternate(){
			port_dir_type::set_pin_alternate();
		}
		static void set_pin_high(){
			port_dir_type::bit_set();
		}
		static void set_pin_low(){
			port_dir_type::bit_clear();
		}
		static bool read_input_value(){
			return port_inp_type::bit_get();
		}
		static void toggle(){
			port_pin_type::bit_not();
		}
		
		private:
			/**/
			static const std::uint32_t idr_offset = 0x10;
			static const std::uint32_t odr_offset = 0x14;
			/**/
			static const addr_type p_odr = port + odr_offset;
			static const addr_type p_idr = port + idr_offset;
			/**/
			typedef reg_access<addr_type, reg_type, p_odr, bpos> port_pin_type;
			typedef reg_access<addr_type, reg_type, port, bpos> port_dir_type;
			typedef reg_access<addr_type, reg_type, p_idr, bpos> port_inp_type;
			
};

int main(void){
	const std::uint32_t ahb1enr = mcal::reg::rcc::ahb1enr;
	const std::uint32_t gpioi = mcal::reg::gpio::gpioi;
	
	/*Enable clock access PORT I*/
	typedef reg_access<std::uint32_t, std::uint32_t, ahb1enr, 8U> ahb1enr_b8_type;
	ahb1enr_b8_type::bit_set();
	
	/*Set Pin 7 as output*/
	typedef port_pin<std::uint32_t, std::uint32_t, gpioi, 7U> pi7_type;
	pi7_type::set_direction_output();
	

	while(1){
		/*Toggle Pin 7 - Red LED*/
		pi7_type::toggle();
		for(int i=0;i<1000;i++){}
	}
}

