/*
 * Bit_Math.h
 *
 *  Created on: Nov 12, 2021
 *      Author: Eng_Fawzi
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NO) 			REG|=(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO) 			REG&=~(1<<BIT_NO)
#define CHK_BIT(REG,BIT_NO) 			((REG>>BIT_NO)&0x01)
#define TOGGLE_BIT(REG,BIT_NO)    		REG^=(1<<BIT_NO)


#endif /* BIT_MATH_H_ */
