/*
 * ICP_REG.h
 *
 *  Created on: Feb 11, 2022
 *      Author: ali
 */

#ifndef _INC_ICP_REG_H_
#define _INC_ICP_REG_H_

#include "Std_Types.h"

#define TIMSK     	(*(volatile u8*)(0x59))
#define TCCR1A     	(*(volatile u8*)(0x4F))

#define TCNT1     	(*(volatile u16*)(0x4C))
#define TCCR1B     	(*(volatile u8*)(0x4E))
#define TIFR     	(*(volatile u8*)(0x58))
#define ICR1     	(*(volatile u16*)(0x46))

#endif /* MCAL_ICP_INC_ICP_REG_H_ */
