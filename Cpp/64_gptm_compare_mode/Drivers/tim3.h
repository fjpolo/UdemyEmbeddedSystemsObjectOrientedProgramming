#ifndef __TIM3_H
#define __TIM3_H

/*mcal_reg*/
#include "mcal_reg.h"

void tim3_init_1hz(void);
void tim3_wait_for_timeout(void);

#endif