/*
 * Servo.c
 *
 *  Created on: Feb 14, 2022
 *      Author: ali
 */

#include "Servo.h"

void Servo_Init(){
	PWM2_Init();
}

void Servo_Angle(u8 angle){
	OCR2 = angle;
}
