/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: ali
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include "Lcd.h"
#include "Ultra_Sonic.h"
#include "Glbl_INT.h"
#include "Servo.h"
#include "DC_Motor.h"

u8 TimerOverflow = 0;

ISR(TIMER1_OVF_vect) {
	TimerOverflow++; /* Increment Timer Overflow count */
}

int main(void) {

	double distance = 00.00;

	PORTD = 0xFF;
	Servo_Init();
	Lcd_Init();
	Lcd_Cmd(_LCD_CLEAR);
	_delay_ms(1000);
	Glbl_Interrupt_Enable();
	UltraSonic_Init();
	DC_Motor_Init();
	u8 Current_case = 0;
	u8 Duty = 20;
	DC_Motor_Forward();
	while (1) {
		switch (Current_case) {
		case 1:
			while (distance <= 10 && Duty != 45) {
				DC_Motor_Stop();
				Lcd_Cmd(_LCD_CLEAR);
				Lcd_Goto_Row_Column(0, 0);
				Lcd_DisplayStr("Check Left Gap");
				Servo_Angle(Duty);
				Duty += 5;
				Trigger_UltraSonic();
				distance = Echo_UltraSonic(TimerOverflow);
				_delay_ms(1000);
				if (distance <= 10) {
					Current_case = 2;
				}
				if (distance > 10) {
					DC_Motor_Stop();
					Lcd_Cmd(_LCD_CLEAR);
					Lcd_Goto_Row_Column(0, 0);
					Lcd_DisplayStr("Prepare for GoTo Gap");
					Current_case = 0;
					Servo_Angle(20);
					_delay_ms(1000);
					Trigger_UltraSonic();
					distance = Echo_UltraSonic(TimerOverflow);
					while (distance <= 10) {
						DC_Motor_CW();
						Lcd_Cmd(_LCD_CLEAR);
						Lcd_Goto_Row_Column(0, 0);
						Lcd_DisplayStr("Turn Left");
						Trigger_UltraSonic();
						distance = Echo_UltraSonic(TimerOverflow);
						_delay_ms(1000);
					}
				}
			}
			break;
		case 2:
			Duty = 20;
			while (distance < 10 && Duty >= 1) {
				DC_Motor_Stop();
				Lcd_Cmd(_LCD_CLEAR);
				Lcd_Goto_Row_Column(0, 0);
				Lcd_DisplayStr("Check Right Gap");
				Servo_Angle(Duty);
				Duty -= 5;
				Trigger_UltraSonic();
				distance = Echo_UltraSonic(TimerOverflow);
				_delay_ms(1000);
				if (distance <= 10) {
					Current_case = 3;
				}
				if (distance > 10) {
					DC_Motor_Stop();
					Lcd_Cmd(_LCD_CLEAR);
					Lcd_Goto_Row_Column(0, 0);
					Lcd_DisplayStr("Prepare for GoTo Gap");
					Current_case = 0;
					Servo_Angle(20);
					_delay_ms(1000);
					Trigger_UltraSonic();
					distance = Echo_UltraSonic(TimerOverflow);
					while (distance <= 10) {
						DC_Motor_ACW();
						Lcd_Cmd(_LCD_CLEAR);
						Lcd_Goto_Row_Column(0, 0);
						Lcd_DisplayStr("Turn Right");
						Trigger_UltraSonic();
						distance = Echo_UltraSonic(TimerOverflow);
						_delay_ms(1000);
					}

				}

			}
			break;
		case 3:
			while (distance <= 10) {
				DC_Motor_ACW();
				Lcd_Cmd(_LCD_CLEAR);
				Lcd_Goto_Row_Column(0, 0);
				Lcd_DisplayStr("Turn And Check Any Gap");
				Trigger_UltraSonic();
				distance = Echo_UltraSonic(TimerOverflow);
				_delay_ms(1000);
			}
			while(distance > 10){
				DC_Motor_Stop();
				Lcd_Cmd(_LCD_CLEAR);
				Lcd_Goto_Row_Column(0, 0);
				Lcd_DisplayStr("Prepare for GoTo Gap");
				DC_Motor_Stop();
				Current_case = 0;
				Servo_Angle(20);
				_delay_ms(1000);
				while(distance <= 10){
					DC_Motor_ACW();
					Lcd_Cmd(_LCD_CLEAR);
					Lcd_Goto_Row_Column(0, 0);
					Lcd_DisplayStr("Trun Right");
					Trigger_UltraSonic();
					distance = Echo_UltraSonic(TimerOverflow);
					_delay_ms(1000);
				}
			}
			break;
		default:

			DC_Motor_Forward();
			Lcd_Cmd(_LCD_CLEAR);
			Lcd_Goto_Row_Column(0, 0);
			Lcd_DisplayStr("Go Forward");
			while (distance > 10) {
				Trigger_UltraSonic();
				distance = Echo_UltraSonic(TimerOverflow);
				_delay_ms(1000);
			}
			Current_case = 1;
		}


	}

}

