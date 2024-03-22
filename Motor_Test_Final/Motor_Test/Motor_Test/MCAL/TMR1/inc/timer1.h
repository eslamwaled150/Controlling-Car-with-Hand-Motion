/*
 * timer1.h
 *
 * Created: 3/19/2024 4:57:12 PM
 *  Author: Omar
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/* UTILES_LIB */
#include "Clock.h"
#include "STD_Types.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_config.h"
#include "DIO_interface.h"
#include "timer1.h"


void PWM_init(void);
void PWM_stop(void);
void PWM_car_speed_Range(u8 dytyrange);
void TMR1_setCompareMatchValueA(u16 compareValue);
void TMR1_setCompareMatchValueB(u16 compareValue);



#endif /* TIMER1_H_ */