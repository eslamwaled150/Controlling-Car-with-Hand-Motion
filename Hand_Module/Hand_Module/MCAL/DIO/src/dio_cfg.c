/*
 * module name: 	 DIO (Digital Input Output)
 * file name :       dio_cfg.c
 * file description: this file contains DIO implementation of function of this module
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */ 


#include "dio_cfg.h"

DIO_PinCfg gol_PinCfg[] ={		// define configuration (direction) of all DIO pins
	
	//PORTA
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
		
	//PORTB
	{Input,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTC
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
		
	//PORTD
	{Input,STD_Low},
	{Input,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}	
};


void MDIO_vidInit()
{
	DIO_PortTypes loc_enumDDRx;
	DIO_ChannelTypes loc_enumBitNo;
	
	DIO_ChannelTypes loc_count = DIO_ChannelA0;
	
	for(loc_count = DIO_ChannelA0; loc_count < PINCOUNT; loc_count++)		// for loop to assign all DIO pin configuration (direction)
	{
		loc_enumDDRx = loc_count/8;
		loc_enumBitNo = loc_count % 8;
		
		switch(loc_enumDDRx)
		{
			case DIO_PORTA:
			{
				if(gol_PinCfg[loc_count].STD_Direction == Output)
				{
					SET_BIT(DDRA_reg,loc_enumBitNo);
				}
				else
				{
					CLEAR_BIT(DDRA_reg,loc_enumBitNo);
				}
				break;
			}
			case DIO_PORTB:
			{
				if(gol_PinCfg[loc_count].STD_Direction == Output)
				{
					SET_BIT(DDRB_reg,loc_enumBitNo);
				}
				else
				{
					CLEAR_BIT(DDRB_reg,loc_enumBitNo);
				}
				break;
			}
			case DIO_PORTC:
			{
				if(gol_PinCfg[loc_count].STD_Direction  == Output)
				{
					SET_BIT(DDRC_reg,loc_enumBitNo);
				}
				else
				{
					CLEAR_BIT(DDRC_reg,loc_enumBitNo);
				}
				break;
			}
			case DIO_PORTD:
			{
				if(gol_PinCfg[loc_count].STD_Direction  == Output)
				{
					SET_BIT(DDRD_reg,loc_enumBitNo);
				}
				else
				{
					CLEAR_BIT(DDRD_reg,loc_enumBitNo);
				}
				break;
			}
		}
	}	
}
