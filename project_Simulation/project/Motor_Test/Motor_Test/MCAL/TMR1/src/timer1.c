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
	
	// Select Prescaler Value = 64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	//set pwm freq 
	
	//ICR1_u16 = F_CPU / (1*(1024+1));
	//dytycycle
	//OCR1A_u16 = 10000; //F_CPU / (1*(1024+1))
	//OCR1B_u16 = 10000;
	
}

void PWM_stop(void)
{
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

void PWM_car_speed_Range(u8 dytyCycle)
{
	if(dytyCycle<=100)
	{
		// under condition non inverting fast pwm & tick time 4 MS

		ICR1_u16 = ((1000000UL/50)/4)-1;
		
		OCR1A_u16 = ((dytyCycle*(ICR1_u16+1))/100.0)-1;
		OCR1B_u16 = ((dytyCycle*(ICR1_u16+1))/100.0)-1;
	}	
}

void TMR1_setCompareMatchValueA(u16 compareValue)
{
	OCR1A_u16 = compareValue;
}

void TMR1_setCompareMatchValueB(u16 compareValue)
{
	OCR1B_u16 = compareValue;
}

/*void TMR1_setFastPWM_usingMode14(f32 dytyCycle)
{
	if(dytyCycle<=100)
	{
		// under condition non inverting fast pwm & tick time 4 MS

		ICR1_u16 = ((1000000UL/1000)/4)-1;
		
		OCR1A_u16 = ((dytyCycle*(ICR1_u16+1))/100.0)-1;
		OCR1B_u16 = ((dytyCycle*(ICR1_u16+1))/100.0)-1;
	}
}*/

