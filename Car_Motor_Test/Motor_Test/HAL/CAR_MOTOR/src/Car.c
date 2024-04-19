#include "Car.h"
#include "Car_Confg.h"
#include "DIO_interface.h"
#include "timer1.h"

void CarMotor_init()
{
	PWM_init();
	
	DIO_init();
	
	// Enable A And B
	DIO_setPinDirection(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_EN2_PORT,MOTORS_CAR_EN2_PIN,DIO_PIN_OUTPUT);
	
	//motorA
	DIO_setPinDirection(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_OUTPUT);
	
	//motorB
	DIO_setPinDirection(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_OUTPUT);
	
	//Enable A and B values
	//DIO_setPinValue(MOTORS_CAR_EN1_PORT,MOTORS_CAR_EN1_PIN,DIO_PIN_HIGH);
	//DIO_setPinValue(MOTORS_CAR_EN2_PORT,MOTORS_CAR_EN2_PIN,DIO_PIN_HIGH);
}

void CarMotor_Stop()
{
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_LOW);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_LOW);
}

void CarMotor_backword(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_HIGH);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_HIGH);
}

void CarMotor_forward(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_LOW);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_LOW);
}

void CarMotor_toRight(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_LOW);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_LOW);
}

void CarMotor_toLeft(u8 SpeedRange)
{
	//speed control
	PWM_car_speed_Range(SpeedRange);
	
	//motorA Left motor
	DIO_setPinValue(MOTORS_CAR_C3_PORT,MOTORS_CAR_C3_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C4_PORT,MOTORS_CAR_C4_PIN,DIO_PIN_HIGH);
	
	//motorB Right motor
	DIO_setPinValue(MOTORS_CAR_C5_PORT,MOTORS_CAR_C5_PIN,DIO_PIN_LOW);
	DIO_setPinValue(MOTORS_CAR_C6_PORT,MOTORS_CAR_C6_PIN,DIO_PIN_LOW);
}