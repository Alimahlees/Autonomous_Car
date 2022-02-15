/*
 * ICP.c
 *
 *  Created on: Feb 11, 2022
 *      Author: ali
 */

#include "ICP.h"

void ICP_Init(){
	//TIMSK = (1 << 1);	/* Enable Timer1 overflow interrupts */
	SET_BIT(TIMSK, 2);
	TCCR1A = 0;		/* Set all bit to zero Normal operation */
	Dio_ConfigChannel(DIO_PORTB, DIO_PIN0, INPUT);

}


u32 ICP_Value(u8 TimerOverflow){
			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
			TIFR = 1<<5;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<2;	/* Clear Timer Overflow flag */

			/*Calculate width of Echo by Input Capture (ICP) */

			while ((TIFR & (1 << 5)) == 0);/* Wait for rising edge */
			TCNT1 = 0;	/* Clear Timer counter */
			TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
			TIFR = 1<<5;	/* Clear ICP flag (Input Capture flag) */
			TIFR = 1<<2;	/* Clear Timer Overflow flag */
			TimerOverflow = 0;/* Clear Timer overflow count */

			while ((TIFR & (1 << 5)) == 0);/* Wait for falling edge */
			u32 count = ICR1 + (65535 * TimerOverflow);	/* Take count */
			return count;
			/* 8MHz Timer freq, sound speed =343 m/s */


}
