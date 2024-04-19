/*
* module name: 		DIO (Digital Input Output)
* file name :       dio.c
* file description: this file contains DIO implementation of function of this module
* version: 			v01
* date:    			29/9/2023
* author:  			Salma Motaz
*/

#include "dio.h"

void MDIO_vidWriteChannel(DIO_ChannelTypes cpy_enumChannelId, STD_LevelTypes cpy_enumLevel)	//function to set single pin value
{
	DIO_PortTypes loc_enumPortx = cpy_enumChannelId/8;				// determined port number
	DIO_ChannelTypes loc_enumBitNo = cpy_enumChannelId % 8;			// determined pin number
	
	switch(loc_enumPortx)								// switch case to determined pin port
	{
		case DIO_PORTA:
		{
			if(cpy_enumLevel == STD_High)
			{
				SET_BIT(PORTA_reg,loc_enumBitNo);		//set pin value
			}
			else
			{
				CLEAR_BIT(PORTA_reg,loc_enumBitNo);		//set pin clear
			}
			break;
		}
		case DIO_PORTB:
		{
			if(cpy_enumLevel == STD_High)
			{
				SET_BIT(PORTB_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(PORTB_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
		case DIO_PORTC:
		{
			if(cpy_enumLevel == STD_High)
			{
				SET_BIT(PORTC_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(PORTC_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
		case DIO_PORTD:
		{
			if(cpy_enumLevel == STD_High)
			{
				SET_BIT(PORTD_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(PORTD_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
	}
}
STD_LevelTypes MDIO_vidReadChannel(DIO_ChannelTypes cpy_enumChannelId)		//function to read single pin value			
{
	DIO_PortTypes loc_enumPortx = cpy_enumChannelId/8;			// determined port number
	DIO_ChannelTypes loc_enumBitNo = cpy_enumChannelId % 8;		// determined pin number
	STD_LevelTypes loc_enumBitValue = STD_Low;
	switch(loc_enumPortx)										//switch case to read single pin
	{
		case DIO_PORTA: { loc_enumBitValue = GET_BIT(PINA_reg,loc_enumBitNo);	break; }
		case DIO_PORTB: { loc_enumBitValue = GET_BIT(PINB_reg,loc_enumBitNo);	break; }
		case DIO_PORTC:	{ loc_enumBitValue = GET_BIT(PINC_reg,loc_enumBitNo);	break; }
		case DIO_PORTD:	{ loc_enumBitValue = GET_BIT(PIND_reg,loc_enumBitNo);	break; }
	}
	return loc_enumBitValue;
}
void MDIO_vidConfigChannel(DIO_ChannelTypes cpy_enumChannelId, DIO_DirTypes cpy_enumDirection)	//function to set single pin configuration
{
	DIO_PortTypes loc_enumDDRx = cpy_enumChannelId/8;			// determined port number
	DIO_ChannelTypes loc_enumBitNo = cpy_enumChannelId % 8;		// determined pin number
	
	switch(loc_enumDDRx)
	{
		case DIO_PORTA:
		{
			if(cpy_enumDirection == Output)
			{
				SET_BIT(DDRA_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(DDRA_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
		case DIO_PORTB:
		{
			if(cpy_enumDirection == Output)
			{
				SET_BIT(DDRB_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(DDRB_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
		case DIO_PORTC:
		{
			if(cpy_enumDirection == Output)
			{
				SET_BIT(DDRC_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(DDRC_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
		case DIO_PORTD:
		{
			if(cpy_enumDirection == Output)
			{
				SET_BIT(DDRD_reg,loc_enumBitNo);		//set pin direction output
			}
			else
			{
				CLEAR_BIT(DDRD_reg,loc_enumBitNo);		//set pin direction input
			}
			break;
		}
	}
}

void MDIO_vidTogggleChannel(DIO_ChannelTypes cpy_enumChannelId)				// function to toggle specific pin value
{
	DIO_PortTypes loc_enumPortx = cpy_enumChannelId/8;					// determined port number
	DIO_ChannelTypes loc_enumBitNo = cpy_enumChannelId % 8;				// determined pin number
	
	switch(loc_enumPortx)
	{
		case DIO_PORTA: { TOGGLE_BIT(PORTA_reg,loc_enumBitNo);	break; }
		case DIO_PORTB:	{ TOGGLE_BIT(PORTB_reg,loc_enumBitNo);	break; }
		case DIO_PORTC:	{ TOGGLE_BIT(PORTC_reg,loc_enumBitNo);	break; }
		case DIO_PORTD: { TOGGLE_BIT(PORTD_reg,loc_enumBitNo);	break; }
	}
}

u8 MDIO_u8ReadPort(DIO_PortTypes cpy_enumPortId)									// function to read specific port value
{
	u8 loc_u8PortValue = STD_Low;
	
	switch(cpy_enumPortId)
	{
		case DIO_PORTA: { loc_u8PortValue = PORTA_reg;	break; }
		case DIO_PORTB:	{ loc_u8PortValue = PORTB_reg;	break; }
		case DIO_PORTC:	{ loc_u8PortValue = PORTC_reg;	break; }
		case DIO_PORTD: { loc_u8PortValue = PORTD_reg;	break; }
	}
	return loc_u8PortValue ;
}
void MDIO_vidWritePort(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue)			// function to set write port configuration
{
	switch(cpy_enumPortId)
	{
		case DIO_PORTA: { PORTA_reg = cpy_u8PortValue;	break; }
		case DIO_PORTB:	{ PORTB_reg = cpy_u8PortValue;	break; }
		case DIO_PORTC:	{ PORTC_reg = cpy_u8PortValue;	break; }
		case DIO_PORTD: { PORTD_reg = cpy_u8PortValue;	break; }
	}
}

void MDIO_vidConfigPort(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue)			// function to set specific port configuration
{
	switch(cpy_enumPortId)
	{
		case DIO_PORTA: { DDRA_reg = cpy_u8PortValue; break; }
		case DIO_PORTB:	{ DDRB_reg = cpy_u8PortValue; break; }
		case DIO_PORTC:	{ DDRC_reg = cpy_u8PortValue; break; }
		case DIO_PORTD: { DDRD_reg = cpy_u8PortValue; break; }
	}
}

void MDIO_vidWriteChannelGroup(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue, u8 cpy_u8Mask)			//function to write specific channel group
{
	switch(cpy_enumPortId)
	{
		case DIO_PORTA: { PORTA_reg = ((PORTA_reg & ~cpy_u8Mask) | (cpy_u8PortValue & cpy_u8Mask));	break; }
		case DIO_PORTB:	{ PORTB_reg = ((PORTB_reg & ~cpy_u8Mask) | (cpy_u8PortValue & cpy_u8Mask));	break; }
		case DIO_PORTC:	{ PORTC_reg = ((PORTC_reg & ~cpy_u8Mask) | (cpy_u8PortValue & cpy_u8Mask));	break; }
		case DIO_PORTD: { PORTD_reg = ((PORTD_reg & ~cpy_u8Mask) | (cpy_u8PortValue & cpy_u8Mask));	break; }
	}
}