/*
 * Ultra_Sonic.c
 *
 *  Created on: Feb 10, 2022
 *      Author: ali
 */

#include "Ultra_Sonic.h"
#include <avr/io.h>
#include "ICP.h"

#define  Trigger_pin	PA0
void UltraSonic_Init(){
	Dio_ConfigChannel(DIO_PORTA, DIO_PIN0, OUTPUT);
	ICP_Init();

}

void Trigger_UltraSonic(){


	Dio_WriteChannel(DIO_PORTA, DIO_PIN0, STD_HIGH);
	_delay_us(10);
	Dio_WriteChannel(DIO_PORTA, DIO_PIN0, STD_LOW);
}


u32 Echo_UltraSonic(u8 TimerOverflow){
	u32 count = ICP_Value(TimerOverflow);
	double distance = (double)count / 466.47;
	return distance;
}


