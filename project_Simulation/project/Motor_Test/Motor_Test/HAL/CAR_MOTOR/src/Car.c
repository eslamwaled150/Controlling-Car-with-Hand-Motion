/*
 * Car.c
 *
 * Created: 3/21/2024 10:25:57 AM
 *  Author: Omar
 */ 

#include "Car.h"
#include "Car_Confg.h"
#include "DIO_interface.h"
#include "timer1.h"

void CarMotor_init()
{
	 PWM_init();
	 
	DIO_init();
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	
	//motorA
	DIO_setPinDirection(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_OUTPUT);
															 
	//motorB												 
	DIO_setPinDirection(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_OUTPUT);
	
	//Enable A and B values
	DIO_setPinValue(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_HIGH);
    DIO_setPinValue(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_HIGH);
}

void CarMotor_Stop(u8 SpeedRange)
{
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_LOW);
														 
	//motorB Right motor								 
	DIO_setPinValue(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_LOW);
}

void CarMotor_backword(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	
	//motorA
	DIO_setPinValue(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_LOW);
	
	//motorB
	DIO_setPinValue(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_LOW);
}

void CarMotor_forward(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_HIGH);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_HIGH);
}

void CarMotor_toRight(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_LOW);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_HIGH);
}

void CarMotor_toLeft(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN0_PORT,MOTORS_CAR_EN0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_A2_PORT,MOTORS_CAR_A2_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A3_PORT,MOTORS_CAR_A3_PIN,DIO_PIN_HIGH);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_A4_PORT,MOTORS_CAR_A4_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_A5_PORT,MOTORS_CAR_A5_PIN,DIO_PIN_LOW);
}