#pragma once

//#include <cstdint> 
#include <stdint.h>


void systick_init_1sec(void);
int systick_get_count_flag(void);
void systick_delayMs(std::uint32_t ms);

