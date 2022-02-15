/*
 * Ultra_Sonic.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ali
 */

#ifndef _INC_ULTRA_SONIC_H_
#define _INC_ULTRA_SONIC_H_

#include "Dio.h"
#include <util/delay.h>

void UltraSonic_Init();

void Trigger_UltraSonic();

u32 Echo_UltraSonic(u8 TimerOverflow);


#endif /* HAL_ULTRA_SONIC_INC_ULTRA_SONIC_H_ */
