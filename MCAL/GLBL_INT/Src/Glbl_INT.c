/*
 * Glbl_INT.c
 *
 *  Created on: Dec 3, 2021
 *      Author: Eng_Fawzi
 */

#include "Glbl_INT.h"

void Glbl_Interrupt_Enable()
{
	SET_BIT(GLBL_SREG_REG,7);
}
void Glbl_Interrupt_Disable()
{
	CLR_BIT(GLBL_SREG_REG,7);
}
