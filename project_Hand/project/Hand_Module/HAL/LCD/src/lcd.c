/*
* module name: 		LCD (Liquid Crystal Display)
* file name :       lcd.c
* file description: this file contains DIO implementation of function of this module
* version: 			v01
* date:    			30/9/2023
* author:  			Salma Motaz
*/

#include "lcd.h"

void HLCD_vidInit()
{
	/* Clear Register Select Pin (Write Command) */
	MDIO_vidWriteChannel(LCD_RS,STD_Low);
	
	/* Select write in Read/Write pin */
	MDIO_vidWriteChannel(LCD_RW,STD_Low);
	
	/* Set Enable pin */
	MDIO_vidWriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	
	/* Send initialization instruction for LCD */
	HLCD_vidSendCommend(0x33);
	
	/* Send for 4 bit initialization of LCD  */
	HLCD_vidSendCommend(0x32);	
	
	/* Function set 4Bit 2Line 5X8 */
	HLCD_vidSendCommend(0x28); 
	
	/* Entry mode shift to right */
	HLCD_vidSendCommend(0x06); 
	
	/* Display on & cursor & blinking off */
	HLCD_vidSendCommend(0x0C); 
}

void HLCD_vidSendCommend(u8 cpy_u8Commend)
{
	u8 loc_u8PortValue = STD_Low;

	MDIO_vidWriteChannel(LCD_RS,STD_Low);	/* Select write in Read/Write pin */
	
	/* Read port value */
	loc_u8PortValue = MDIO_u8ReadPort(LCD_DataPort);
	
	/* Set port value with upper nibble in command and maintain other port value */
	loc_u8PortValue =  (loc_u8PortValue & 0x0f) | (cpy_u8Commend & 0xf0);
	
	/* Set port value with command and maintain other port value */
	MDIO_vidWritePort(LCD_DataPort, loc_u8PortValue);
	
	/* Create enable trigger to send data */
	MDIO_vidWriteChannel(LCD_E,STD_Low);	/* Clear Enable pin */
	_delay_us(100);							/* wait 100 microsecond */
	MDIO_vidWriteChannel(LCD_E,STD_High);	/* Set Enable pin */
	_delay_ms(5);							/* Wait to send command */
		
	/* Read port value */
	loc_u8PortValue = MDIO_u8ReadPort(LCD_DataPort);
	
	/* Set port value with lower nibble in command and maintain other port value */
	loc_u8PortValue =  (loc_u8PortValue & 0x0f) | (cpy_u8Commend << 4);

	/* Set port value with command and maintain other port value */
	MDIO_vidWritePort(LCD_DataPort, loc_u8PortValue); 
	
	/* Create enable trigger to send data */
	MDIO_vidWriteChannel(LCD_E,STD_Low);	/* Clear Enable pin */
	_delay_us(100);							/* wait 100 microsecond */
	MDIO_vidWriteChannel(LCD_E,STD_High);	/* Set Enable pin */
	_delay_ms(2);							/* Wait to send command */
}

void HLCD_vidSendChar (u8 cpy_u8Data)
{
	u8 loc_u8PortValue = STD_Low;			
	MDIO_vidWriteChannel(LCD_RS,STD_High);	/* Select write in Read/Write pin */
	
	/* Read port value */
	loc_u8PortValue = MDIO_u8ReadPort(LCD_DataPort);
	
	/* Set port value with upper nibble bit in command and maintain other port value */
	loc_u8PortValue =  (loc_u8PortValue & 0x0f) | (cpy_u8Data & 0xf0);
	
	/* Set port value with command and maintain other port value */
	MDIO_vidWritePort(LCD_DataPort, loc_u8PortValue);
	
	/* Create enable trigger to send data */
	MDIO_vidWriteChannel(LCD_E,STD_Low);	/* Clear Enable pin */
	_delay_ms(1);							/* wait 1 millisecond */
	MDIO_vidWriteChannel(LCD_E,STD_High);	/* Set Enable pin */
	_delay_ms(5);							/* Wait to send command */
	
	/* Read port value */
	loc_u8PortValue = MDIO_u8ReadPort(LCD_DataPort);
	
	/* Set port value with lower nibble bit in command and maintain other port value */
	loc_u8PortValue =  (loc_u8PortValue & 0x0f) | (cpy_u8Data << 4);	
	
	/* Set port value with command and maintain other port value */
	MDIO_vidWritePort(LCD_DataPort, loc_u8PortValue);
	
	/* Create enable trigger to send data */
	MDIO_vidWriteChannel(LCD_E,STD_Low);	/* Clear Enable pin */
	_delay_ms(1);							/* wait 1 millisecond */
	MDIO_vidWriteChannel(LCD_E,STD_High);	/* Set Enable pin */
	_delay_ms(2);							/* Wait to send command */
}

void HLCD_vidSendString(s8 * cpy_s8PTString)		/* Function to send string */
{
	u8 loc_u8Count = STD_Low;
	
	while(cpy_s8PTString [loc_u8Count] != '\0')		/* while loop to send string char by char*/
	{
		HLCD_vidSendChar(cpy_s8PTString[loc_u8Count]);
		loc_u8Count++;
	}
}

void HLCD_vidSendNumber(s32 cpy_s32Number)		// Function to send number to LCD
{
	u32 cpy_u32power = 1;
	s32 cpy_s32num = cpy_s32Number;
	if (cpy_s32Number == 0)						//if condition to check if number equal zero
	{
		HLCD_vidSendChar('0');					//print zero in LCD screen
		return;
	}
	if (cpy_s32Number < 0)						//if condition to check if number less than zero
	{
		HLCD_vidSendChar('-');					//print - in LCD screen if number is negative number 
		cpy_s32Number *= -1;
	}
	cpy_s32num = cpy_s32Number;
	while(cpy_s32num)							// while loop to determined number of digits of number 
	{
		cpy_s32num /= 10;
		cpy_u32power *= 10;
	}

	cpy_u32power/=10;

	while(cpy_u32power > 0)						    // while loop to check if power more than zero 
	{
		cpy_s32num = cpy_s32Number/cpy_u32power;	// take last digit in number
		cpy_s32Number %=cpy_u32power;				// take reminder of digits in number without last digit
		cpy_u32power/=10;							// decrease power digit
		HLCD_vidSendChar(cpy_s32num +'0');			// print number in ascii 
	}
}

void HLCD_vidSendFloat(f64 cpy_f64Float)			// Function to send float number to LCD
{
	u32 cpy_u32power = 1;
	s32 cpy_s32num = cpy_f64Float;
	s32 i =0;
	if (cpy_f64Float == 0)							// if condition to check if float number equal zero 
	{
		HLCD_vidSendChar('0');						//print zero in LCD screen
		return;
	}
	if(cpy_f64Float > 0 && cpy_f64Float < 1)		// if condition to check if float number greater than zero and less than one
	{
		HLCD_vidSendChar('0');						//print zero in LCD screen
	}
	if (cpy_f64Float < 0)							// if condition to check if float number less than zero
	{
		HLCD_vidSendChar('-');						//print - in LCD screen if number is negative number 
		if(cpy_f64Float > -1 && cpy_f64Float < 0)	// if condition to check if float number less than zero and less than negative one
		{
			HLCD_vidSendChar('0');					//print zero in LCD screen
		}
		cpy_f64Float *= -1;							//convert number to positive number
	}
	cpy_s32num = cpy_f64Float;
	while(cpy_s32num)								// while loop to determined number of whole number digits  
	{
		cpy_s32num /= 10;
		i++;
		cpy_u32power *= 10;
	}
	s32 int_num  = cpy_f64Float*10000;
	cpy_u32power *= 1000;					    // increase power with number of accuracy needed after decimal point

	while(cpy_u32power > 0)						// while loop to check if power more than zero
	{
		cpy_s32num = int_num/cpy_u32power;		// take last digit in number
		int_num %= cpy_u32power;				// take reminder of digits in number without last digit
		cpy_u32power /=  10;					// decrease power digit
		
		if(i == 0)								// if condition to check location of decimal point
		{
			HLCD_vidSendChar('.');				// print point in LCD screen
		}
		i--;
		HLCD_vidSendChar(cpy_s32num +'0');		// print number in ascii
	}
}

void HLCD_vidSetPosition(u8 cp_u8Line, u8 cp_u8position)		// Function To select LCD line
{
	switch(cp_u8Line)
	{
		case 1: { HLCD_vidSendCommend(0x80 | (cp_u8position & 0x0F)); break; }	// Send Command to select 1 line in LCD screen
		case 2: { HLCD_vidSendCommend(0xC0 | (cp_u8position & 0x0F)); break; }	// Send Command to select 2 line in LCD screen
	}
}

void HLCD_vidCustomChar(u8 cpy_u8Location, s8*  cpy_s8PTMassaged)
{
	if(cpy_u8Location < 8)
	{
		HLCD_vidSendCommend(0x40 + (cpy_u8Location *8));	// Send Command to save Custom Char 
		
		u8 loc_u8Count = 0;
		for(loc_u8Count = 0; loc_u8Count < 8; loc_u8Count++)
		{
			HLCD_vidSendChar(cpy_s8PTMassaged[loc_u8Count]);	// print Custom Char on LCD
		}
	}
}

void HLCD_vidClearScreen()
{
	HLCD_vidSendCommend(0x01);	// Send Command to clear screen
}