#ifndef __SYSTICK_H
#define __SYSTICK_H

#include <cstdint> 


void systick_init_1sec(void);
int systick_get_count_flag(void);
void systick_delayMs(std::uint32_t ms);

#endif // __SYSTICK_H

