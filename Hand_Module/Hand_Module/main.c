/*
 * module name:		 Hand_Module
 * file name :       Hand_Module.c
 * file description: this file contains Hand module app file
 * version: 		 v01
 * date:    		 3/15/2024 9:49:53 AM
 * author:  		 Salma Motaz
 */ 

	/* Microcontroller clock */
	
#include "clock.h"
#include <util/delay.h>

	/* library */
	
#include "std_types.h"
#include "bitmath.h"

	/* MCAL */

#include "dio_cfg.h"
#include "adc.h"
#include "uart.h"

	/* HAL */
	
#include "lcd.h"
#include "flex_sensor.h"

/* Code Speed Analog Flexible sensor & Motion Analog Flexible sensors */
				
int main(void)
{
	
	// Variable Initiation
	f32 loc_u8MotionState = 0; 
	u8 loc_u8ChosenConvertorCounter = 0, loc_u8MotionDirection = 5, loc_u8Motionflag = 0,loc_u8SendCarState = 0;
	u8 arr_u8MotionChannel[4] = {DIO_ChannelA1,DIO_ChannelA2,DIO_ChannelA3,DIO_ChannelA4};
		   	
	MDIO_vidInit();		 //DIO Initiation
	
	UART_init();   	    //UART Initiation
	
   	HLCD_vidInit();		//LCD Initiation
	   	   
   	STD_ADC_InitType loc_STDOption = {ADC_Vref_AREF, ADC_Prescaler128};		//ADC References voltage and Prescaler
   	
   	HFlexSensor_vidInit(&loc_STDOption);	//Flexible Sensor Initiation
   	
   	while (1)
   	{		 
		loc_u8Motionflag = STD_Low;		// set loc_u8Motionflag variable to low
		
		for(loc_u8ChosenConvertorCounter = 0; loc_u8ChosenConvertorCounter < 4; loc_u8ChosenConvertorCounter++)		// For loop to read 4 motion flex sensor
		{			
			loc_u8MotionState = HFlexSensor_u16AnalogRead(arr_u8MotionChannel[loc_u8ChosenConvertorCounter]);		// Read Value of motion Flex Sensor
			
			if(loc_u8MotionState > 1180.0)			// if condition to check if flex sensor is bended
			{
				if(STD_High == loc_u8Motionflag)	// if condition to check if two or more flex sensor were bended
				{
					loc_u8Motionflag = STD_Low;
					loc_u8MotionDirection = 5;
					break;
				}
				else                               // else condition to select motion direction 
				{
					loc_u8MotionDirection = loc_u8ChosenConvertorCounter;
					loc_u8Motionflag = STD_High;
				}
			}
			else if(STD_Low == loc_u8Motionflag) // else if condition if there no motion order
			{
				loc_u8MotionDirection = 5;
			}

		}
		
		HLCD_vidSetPosition(1,0);			// Select first line in LCD
		HLCD_vidSendString("Direction: ");	// Print 'Direction:' Word in LCD
		
		switch(loc_u8MotionDirection)
		{
			case 0 : { loc_u8SendCarState = 11; HLCD_vidSendChar('F'); break;}	// print F for forward motion order
			case 1 : { loc_u8SendCarState = 12; HLCD_vidSendChar('B'); break;}	// print B for backward motion order
			case 2 : { loc_u8SendCarState = 13; HLCD_vidSendChar('R'); break;}	// print R for right motion order
			case 3 : { loc_u8SendCarState = 14; HLCD_vidSendChar('L'); break;}	// print L for left motion order
			default: { loc_u8SendCarState = 15; HLCD_vidSendString("No M");}		// print No M for no motion order
		}
		

		loc_u8MotionState = HFlexSensor_u16AnalogRead(ADC_Channel0);			// Read Value of Speed Flex Sensor
		
		HLCD_vidSetPosition(2,0);			// Select Second line in LCD
		HLCD_vidSendString("Speed: ");		// Print 'Speed:' Word in LCD
		
		// if else if else condition  to select Speed 
		if(loc_u8MotionState < 1100.0)			// if condition to See if there is no motion
		{
			HLCD_vidSendNumber(0);				// print 0 for no speed
			loc_u8SendCarState = (loc_u8SendCarState | 0x00);
		}
		else if(loc_u8MotionState < 1400.0)		// if condition to See if order of speed first level 
		{
			HLCD_vidSendNumber(1);				// print 1 for first level of speed
			loc_u8SendCarState = (loc_u8SendCarState | 0x10);
		}
		else if(loc_u8MotionState < 1600.0)		// if condition to See if order of speed second level 
		{
			HLCD_vidSendNumber(2);				// print 2 for second level of speed
			loc_u8SendCarState = (loc_u8SendCarState | 0x20);
		}
		else if(loc_u8MotionState < 1810.0)		// if condition to See if order of speed third level 
		{
			HLCD_vidSendNumber(3);				// print 3 for third level of speed
			loc_u8SendCarState = (loc_u8SendCarState | 0x30);
		}
		else									// if condition to See if order of speed fourth level 
		{
			HLCD_vidSendNumber(4);				// print 4 for fourth level of speed
			loc_u8SendCarState = (loc_u8SendCarState | 0x40);
		}
		
		UART_TxChar(loc_u8SendCarState);
		
		_delay_ms(200);
		HLCD_vidClearScreen();
   	}
   	return 0;
}

