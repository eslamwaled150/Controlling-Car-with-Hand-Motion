/*
 * Motor_Test.c
 *
 * Created: 3/21/2024 10:19:33 AM
 * Author : Eslam
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Clock.h"

/* MCAL */
#include "timer1.h"
#include "DIO_interface.h"
#include "UART.h"

/* HAL */
#include "LCD.h"
#include "Car.h"


int main(void)
{
	u8 motorSpeed,motorSpeed_val=0,motorDirection='F';
   DIO_init();
   CarMotor_init();
   UART_init();
   LCD_init();
   LCD_writeString((u8*)"Car is ON");
   
   _delay_ms(200);
   LCD_clear();
    while (1) 
    {
				motorDirection=UART_RxChar();
				motorSpeed_val=UART_RxChar();
				LCD_goToSpecification(LCD_LINE_ONE,0);
				// Set motor speed based on the speed level
				switch (motorSpeed_val)
				{
					case 0:
					motorSpeed = 0;
					LCD_writeString((u8*)"speed: 0");
					break;
					
					case 1:
					motorSpeed = 30;
					LCD_writeString((u8*)"speed: 1");
					break;
					
					case 2:
					motorSpeed = 50;
					LCD_writeString((u8*)"speed: 2");
					break;
					
					case 3:
					motorSpeed = 75;
					LCD_writeString((u8*)"speed: 3");
					break;
					
					case 4:
					motorSpeed = 100;
					LCD_writeString((u8*)"speed: 4");
					break;
					
					default:
					motorSpeed = 0;
					break;
				}
				
				
				LCD_goToSpecification(LCD_LINE_TWO,0);
				switch (motorDirection)
				{
					case 'F':
					// Forward
					LCD_writeString((u8*)"Direction:F");
					CarMotor_forward(motorSpeed);
					break;
					
					case 'B':
					// Backward
					LCD_writeString((u8*)"Direction:B");
					CarMotor_backword(motorSpeed);
					break;
					
					case 'L':
					// Left
					LCD_writeString((u8*)"Direction:L");
					CarMotor_toLeft(motorSpeed);
					break;
					
					case 'R':
					// Right
					LCD_writeString((u8*)"Direction:R");
					CarMotor_toRight(motorSpeed);
					break;
					
					case 'N':
					// Stop
					LCD_writeString((u8*)"Direction:S");
					CarMotor_Stop(0);
					break;
					
					default:
					// Invalid direction, stop the motors
					LCD_sendChar('N');
					CarMotor_Stop(0);
					break;
				}
			_delay_ms(400);	
             LCD_clear();

    }
}

