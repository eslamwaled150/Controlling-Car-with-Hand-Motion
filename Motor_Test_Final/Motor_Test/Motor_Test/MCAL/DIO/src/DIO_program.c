/*
 * DIO_program.c
 *
 *  Created on: Dec 31, 2022
 *      Author: AMIT
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


void DIO_init(void)
{
	/*Set Initial Directions FOR Pins */
	DDRA = CONC(DIO_PA7_INITIAL_DIRECTION,DIO_PA6_INITIAL_DIRECTION,DIO_PA5_INITIAL_DIRECTION,DIO_PA4_INITIAL_DIRECTION,
	            DIO_PA3_INITIAL_DIRECTION,DIO_PA2_INITIAL_DIRECTION,DIO_PA1_INITIAL_DIRECTION,DIO_PA0_INITIAL_DIRECTION);
				
	DDRB = CONC(DIO_PB7_INITIAL_DIRECTION,DIO_PB6_INITIAL_DIRECTION,DIO_PB5_INITIAL_DIRECTION,DIO_PB4_INITIAL_DIRECTION,
	            DIO_PB3_INITIAL_DIRECTION,DIO_PB2_INITIAL_DIRECTION,DIO_PB1_INITIAL_DIRECTION,DIO_PB0_INITIAL_DIRECTION);
				
	DDRC = CONC(DIO_PC7_INITIAL_DIRECTION,DIO_PC6_INITIAL_DIRECTION,DIO_PC5_INITIAL_DIRECTION,DIO_PC4_INITIAL_DIRECTION,
	            DIO_PC3_INITIAL_DIRECTION,DIO_PC2_INITIAL_DIRECTION,DIO_PC1_INITIAL_DIRECTION,DIO_PC0_INITIAL_DIRECTION);
				
    DDRD = CONC(DIO_PD7_INITIAL_DIRECTION,DIO_PD6_INITIAL_DIRECTION,DIO_PD5_INITIAL_DIRECTION,DIO_PD4_INITIAL_DIRECTION,
	            DIO_PD3_INITIAL_DIRECTION,DIO_PD2_INITIAL_DIRECTION,DIO_PD1_INITIAL_DIRECTION,DIO_PD0_INITIAL_DIRECTION);
				
	/*Set Initial Values FOR Pins */
	PORTA = CONC(DIO_PA7_INITIAL_VALUE,DIO_PA6_INITIAL_VALUE,DIO_PA5_INITIAL_VALUE,DIO_PA4_INITIAL_VALUE,
	             DIO_PA3_INITIAL_VALUE,DIO_PA2_INITIAL_VALUE,DIO_PA1_INITIAL_VALUE,DIO_PA0_INITIAL_VALUE);
																								   
	PORTB = CONC(DIO_PB7_INITIAL_VALUE,DIO_PB6_INITIAL_VALUE,DIO_PB5_INITIAL_VALUE,DIO_PB4_INITIAL_VALUE,
	             DIO_PB3_INITIAL_VALUE,DIO_PB2_INITIAL_VALUE,DIO_PB1_INITIAL_VALUE,DIO_PB0_INITIAL_VALUE);
																								   
	PORTC = CONC(DIO_PC7_INITIAL_VALUE,DIO_PC6_INITIAL_VALUE,DIO_PC5_INITIAL_VALUE,DIO_PC4_INITIAL_VALUE,
	             DIO_PC3_INITIAL_VALUE,DIO_PC2_INITIAL_VALUE,DIO_PC1_INITIAL_VALUE,DIO_PC0_INITIAL_VALUE);
																								   
    PORTD = CONC(DIO_PD7_INITIAL_VALUE,DIO_PD6_INITIAL_VALUE,DIO_PD5_INITIAL_VALUE,DIO_PD4_INITIAL_VALUE,
	             DIO_PD3_INITIAL_VALUE,DIO_PD2_INITIAL_VALUE,DIO_PD1_INITIAL_VALUE,DIO_PD0_INITIAL_VALUE);
}

void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if((PortId<=3)&&(PinId<=7)&&((DIO_PIN_OUTPUT==PinDirection)||(DIO_PIN_INPUT==PinDirection)))
	{
		switch(PortId)
		{
		case DIO_PORTA:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRA,PinId);
			}
			else
			{
				CLR_BIT(DDRA,PinId);
			}
			break;

		case DIO_PORTB:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRB,PinId);
			}
			else
			{
				CLR_BIT(DDRB,PinId);
			}
			break;

		case DIO_PORTC:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRC,PinId);
			}
			else
			{
				CLR_BIT(DDRC,PinId);
			}
			break;

		case DIO_PORTD:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRD,PinId);
			}
			else
			{
				CLR_BIT(DDRD,PinId);
			}
			break;
		}
	}

	else
	{
		// Do Nothing
	}
}


void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	if ((PortId<=3)&&(PinId<=7)&&((DIO_PIN_HIGH==PinValue)||(DIO_PIN_LOW==PinValue)))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTA,PinId);
			}
			else
			{
				CLR_BIT(PORTA,PinId);
			}
			break;

			case DIO_PORTB:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTB,PinId);
			}
			else
			{
				CLR_BIT(PORTB,PinId);
			}
			break;

			case DIO_PORTC:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTC,PinId);
			}
			else
			{
				CLR_BIT(PORTC,PinId);
			}
			break;

			case DIO_PORTD:
			if(DIO_PIN_HIGH == PinValue)
			{
				SET_BIT(PORTD,PinId);
			}
			else
			{
				CLR_BIT(PORTD,PinId);
			}
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	if ((PortId<=3) && (PortId<=7) && (PinValue != NULL))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			*PinValue = GET_BIT(PINA,PinId);
			break;

			case DIO_PORTB:
			*PinValue = GET_BIT(PINB,PinId);
			break;

			case DIO_PORTC:
			*PinValue = GET_BIT(PINC,PinId);
			break;

			case DIO_PORTD:
			*PinValue = GET_BIT(PIND,PinId);
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_togglePinValue(u8 PortId, u8 PinId)
{
	if ((PortId<=3) && (PortId<=7))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinId);
			break;

			case DIO_PORTB:
			TOG_BIT(PORTB,PinId);
			break;

			case DIO_PORTC:
			TOG_BIT(PORTC,PinId);
			break;

			case DIO_PORTD:
			TOG_BIT(PORTD,PinId);
			break;
		}
	}
	else
	{
		//DO NOthing
	}
	
}


void DIO_activePinInPullUpResistance(u8 PortId, u8 PinId)
{
	if ((PortId<=3) && (PortId<=7))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,PinId);
			break;

			case DIO_PORTB:
			SET_BIT(PORTB,PinId);
			break;

			case DIO_PORTC:
			SET_BIT(PORTC,PinId);
			break;

			case DIO_PORTD:
			SET_BIT(PORTD,PinId);
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


/* Port Apis */
void DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	if((PortId<=3) && ((DIO_PORT_OUTPUT == PortDirection) || (DIO_PORT_INPUT == PortDirection)))
	{
		switch(PortId)
		{
		case DIO_PORTA:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRA = 0xff; //OUTPUT
			}				 
			else			 
			{				 
				DDRA = 0x00; //INPUT
			}
			break;

		case DIO_PORTB:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRB = 0xff; //OUTPUT
			}
			else
			{
				DDRB = 0x00; //INPUT
			}
			break;

		case DIO_PORTC:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRC = 0xff; //OUTPUT
			}				 
			else			 
			{				 
				DDRC = 0x00; //INPUT
			}
			break;

		case DIO_PORTD:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRD = 0xff; //OUTPUT
			}				 
			else			 
			{				 
				DDRD = 0x00; //INPUT
			}
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_setPortValue(u8 PortId, u8 PortValue)
{
	if(PortId<=3 && ((DIO_PORT_HIGH==PortValue)||(DIO_PORT_LOW==PortValue)))
	{
		switch(PortId)
		{
		case DIO_PORTA:
			PORTA = PortValue;
			break;

		case DIO_PORTB:
			PORTB = PortValue;
			break;

		case DIO_PORTC:
			PORTC = PortValue;
			break;

		case DIO_PORTD:
			PORTD = PortValue;
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_getPortValue(u8 PortId, u8* PortValue)
{
	if((PortId<=3) && (PortValue != NULL))
	{
		switch(PortId)
		{
		case DIO_PORTA:
			*PortValue = PINA;
			break;

		case DIO_PORTB:
			*PortValue = PINB;
			break;

		case DIO_PORTC:
			*PortValue = PINC;
			break;

		case DIO_PORTD:
			*PortValue = PIND;
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_togglePortValue(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
		case DIO_PORTA:
			PORTA = ~PORTA;
			break;

		case DIO_PORTB:
			PORTB = ~PORTB;
			break;

		case DIO_PORTC:
			PORTC = ~PORTC;
			break;

		case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}


void DIO_activePortInPullUpResistance(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
		case DIO_PORTA:
			PORTA = 0xff;
			break;

		case DIO_PORTB:
			PORTB = 0xff;
			break;

		case DIO_PORTC:
			PORTC = 0xff;
			break;

		case DIO_PORTD:
			PORTD = 0xff;
			break;
		}
	}
	else
	{
		//DO NOthing
	}
}
