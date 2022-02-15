/*
 * DC_Motor.c
 *
 *  Created on: Feb 14, 2022
 *      Author: ali
 */

#include "DC_Motor.h"

void DC_Motor_Init() {
	Dio_ConfigChannel(DIO_PORTC, DIO_PIN6, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC, DIO_PIN7, OUTPUT);
}
void DC_Motor_Forward() {
	Dio_WriteChannel(DIO_PORTC, DIO_PIN6, STD_HIGH);
	Dio_WriteChannel(DIO_PORTC, DIO_PIN7, STD_HIGH);
}
void DC_Motor_Stop() {
	Dio_WriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
	Dio_WriteChannel(DIO_PORTC, DIO_PIN7, STD_LOW);
}
void DC_Motor_CW() {
	Dio_WriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
	Dio_WriteChannel(DIO_PORTC, DIO_PIN7, STD_HIGH);
}
void DC_Motor_ACW() {
	Dio_WriteChannel(DIO_PORTC, DIO_PIN7, STD_LOW);
	Dio_WriteChannel(DIO_PORTC, DIO_PIN6, STD_HIGH);
}
