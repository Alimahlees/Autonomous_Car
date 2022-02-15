/*
 * PWM2.c
 *
 *  Created on: Feb 13, 2022
 *      Author: ali
 */
#include "PWM2.h"


void PWM2_Init(){
	TCCR2 = (1<<6) | (1<<3) | (1<<5) | (1<<0) | (1<<1) | (1<<2);

	Dio_ConfigChannel(DIO_PORTD, DIO_PIN7, OUTPUT);

//DDRD|=(1<<PD7);  /*set OC0 pin as output*/
}
