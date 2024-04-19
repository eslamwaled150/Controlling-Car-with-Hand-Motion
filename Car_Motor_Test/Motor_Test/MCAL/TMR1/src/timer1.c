/*
 * timer1.c
 *
 * Created: 3/19/2024 6:31:57 PM
 *  Author: Omar
 */ 

/* UTILES_LIB */
/*#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Clock.h"*/

/* MCAL */
#include "timer1.h"
#include "DIO_interface.h"
#include "timer1_reg.h"

void PWM_init(void)
{
	//set OC1A and OC1B as an output in PD4 and PD5
	DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);//PD4
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);//PD5
	
	// Select Mode = Fast PWM mode 14
	
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	// Select Non Inverting OC1A
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	// Select Non Inverting OC1B
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	
	// Select Prescaler Value = 1
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	 // Set PWM frequency
	 ICR1_u16 = 0xFFFF  ;      //((F_CPU / (1* 65536))); //For 16-bit resolution
	
	// Initialize duty cycle (0% initially)
	OCR1A_u16 = 0;
	OCR1B_u16 = 0;
	
}


void PWM_stop(void)
{
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

// Set compare match value for motor A (optional)
void TMR1_setCompareMatchValueA(u16 compareValue)
{
	OCR1A_u16 = compareValue;
}

// Set compare match value for motor B (optional)
void TMR1_setCompareMatchValueB(u16 compareValue)
{
	OCR1B_u16 = compareValue;
}

// Set car speed range based on duty cycle (0-100)
void PWM_car_speed_Range(u8 dytyCycle)
{
	if(dytyCycle<=100)
	{
		ICR1_u16 =  0xFFFF;   //((F_CPU / (1 * 65536)));
		
		 u16 pwmValue = ((dytyCycle * (65535)) / 100); // Calculate the PWM value corresponding to the duty cycle

		OCR1A_u16 = pwmValue;
		OCR1B_u16 = pwmValue;
	}	
}





