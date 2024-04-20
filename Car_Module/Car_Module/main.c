/*
 * Motor_Test.c
 *
 * Created: 3/21/2024 10:19:33 AM
 * Author : Eslam
 */ 

//* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Clock.h"


/* MCAL */
#include "timer1.h"
#include "DIO_interface.h"
#include "UART.h"
#include "GIE.h"

/* HAL */
#include "LCD.h"
#include "Car.h"

static u8 count = 15;
void UART_RXC_ISR(void)
{
	UART_RxChar(&count);
}

#if 1
int main(void)
{
	u8 motorSpeed,motorSpeed_val=0,motorDirection=15;
	DIO_init();
	CarMotor_init();
	UART_init();
	LCD_init();
	UART_RXC_SetCallback(UART_RXC_ISR);
	UART_RXC_EnableInt();
	GIE_Enable();
	LCD_writeString((u8*)"Car is ON");
	_delay_ms(200);
	
	while (1)
	{
		motorDirection=count&0x0f;
		motorSpeed_val=count>>4;
		LCD_clear();
		LCD_goToSpecification(LCD_LINE_ONE,0);
		
		
		// Set motor speed based on the speed level
		switch (motorSpeed_val)
		{
			case 0:
			motorSpeed = 0;
			LCD_writeString((u8*)"Speed: 0");
			break;
			
			case 1:
			motorSpeed = 30;
			LCD_writeString((u8*)"Speed: 1");
			break;
			
			case 2:
			motorSpeed = 50;
			LCD_writeString((u8*)"Speed: 2");
			break;
			
			case 3:
			motorSpeed = 75;
			LCD_writeString((u8*)"Speed: 3");
			break;
			
			case 4:
			motorSpeed = 100;
			LCD_writeString((u8*)"Speed: 4");
			break;
			
			default:
			motorSpeed = 0;
			LCD_writeString((u8*)"NO speed");
			break;
		}
		
		LCD_goToSpecification(LCD_LINE_TWO,0);
		
			switch (motorDirection)
			{
				case 11:
				// Forward
				LCD_writeString((u8*)"Direction: F");
				CarMotor_forward(motorSpeed);
				break;
				
				case 12:
				// Backward
				LCD_writeString((u8*)"Direction: B");
				CarMotor_backword(motorSpeed);
				break;
				
				case 13:
				// Left
				LCD_writeString((u8*)"Direction: R");
				CarMotor_toRight(motorSpeed);
				break;
				
				case 14:
				// Right
				LCD_writeString((u8*)"Direction: L");
				CarMotor_toLeft(motorSpeed);
				break;
				
				case 15:
				// Stop
				LCD_writeString((u8*)"Direction:S");
				CarMotor_Stop(0);
				break;
				
				default:
				// Invalid direction, stop the motors
				LCD_writeString((u8*)"Not Valid");
				CarMotor_Stop(0);
			}
		
		_delay_ms(300);
	}
}
#endif

