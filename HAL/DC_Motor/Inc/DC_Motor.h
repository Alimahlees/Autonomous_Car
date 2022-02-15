/*
 * DC_Motor.h
 *
 *  Created on: Feb 14, 2022
 *      Author: ali
 */

#ifndef _INC_DC_MOTOR_H_
#define _INC_DC_MOTOR_H_

#include "Dio.h"

	void DC_Motor_Init();
	void DC_Motor_Forward();
	void DC_Motor_Stop();
	void DC_Motor_CW();
	void DC_Motor_ACW();

#endif /* HAL_DC_MOTOR_INC_DC_MOTOR_H_ */
