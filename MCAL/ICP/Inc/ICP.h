/*
 * ICP.h
 *
 *  Created on: Feb 11, 2022
 *      Author: ali
 */

#ifndef _INC_ICP_H_
#define _INC_ICP_H_

#include "ICP_REG.h"
#include "Bit_Math.h"
#include "Dio.h"

void ICP_Init();
u32 ICP_Value(u8 TimerOverflow);


#endif /* MCAL_ICP_INC_ICP_H_ */
