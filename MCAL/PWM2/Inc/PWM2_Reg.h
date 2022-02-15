/*
 * PWM2_Reg.h
 *
 *  Created on: Feb 13, 2022
 *      Author: ali
 */

#ifndef _INC_PWM2_REG_H_
#define _INC_PWM2_REG_H_


#define TCCR2     	(*(volatile u8*)(0x45))
#define TCNT2     	(*(volatile u8*)(0x44))
#define OCR2     	(*(volatile u8*)(0x43))



#endif /* MCAL_TIMER2_INC_PWM2_REG_H_ */
