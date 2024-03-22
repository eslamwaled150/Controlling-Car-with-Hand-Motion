/*
 * LCD.c
 *
 * Created: 3/6/2024 6:14:12 PM
 *  Author: eslam
 */
 
/*  library*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Clock.h"

/* MCAL */
#include "DIO_interface.h"
#include "LCD.h"
#include "LCD_CONFG.h"


void LCD_init(void)
{
	DIO_setPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_E_PORT, LCD_E_PIN ,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	
	_delay_ms(40);
	//set RS Pin = 0 (Write Command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	//Set RW PIN  = 0 (Write)
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,0);
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,1);
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,0);
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,0);
	
	//Enable Pulse    /* H=>L  */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	//FUN set command 2*16  LCD  ,4 Bit Mode
	LCD_sendCmnd(0b00101000);  //LCD_sendCmnd(0x28);
	_delay_us(45);
	
	//Display on off Control (Display on, Cursor on , Blink on)
	LCD_sendCmnd(0b00001111);  //LCD_sendCmnd(0x0F);
	_delay_us(45);
	
	//Clear Display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);  //LCD_sendCmnd(0x01);
	
	//Set Entry Mode (Increment on, shift off)
	LCD_sendCmnd(0b00000110);  //LCD_sendCmnd(0x06);
}
void LCD_sendCmnd(u8 cmnd)
{
	//Set RS PIN  = 0 (write Command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	//Set RW PIN  = 0 (Write)
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	//Write the most 4 bits of command on data pins
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(cmnd,4));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(cmnd,5));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(cmnd,6));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(cmnd,7));
	
	//Enable Pulse    /* H=>L  */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	//Write the Least 4 bits of command on data pins
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(cmnd,0));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(cmnd,1));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(cmnd,2));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(cmnd,3));
	
	//Enable Pulse    /* H=>L  */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
}

void LCD_sendChar(u8 data)
{
	//Set RS PIN  = 1 (write data)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
	//Set RW PIN  = 0 (Write)
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	//Write the most 4 bits of data on Data Pins
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(data,4));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(data,5));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(data,6));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(data,7));
	
	//Enable Pulse    /* H=>L  */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	//Write the most 4 bits of command on data pins
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(data,0));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(data,1));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(data,2));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(data,3));
	
	//Enable Pulse    /* H=>L  */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);	
}

void LCD_writeString(u8* string)
{
	if (string!=NULL)
	{
		u8 counter=0;
		while(string[counter]!='\0')
		{
			LCD_sendChar(string[counter]);
			counter++;
		}
	}
}

void LCD_shift(u8 shifttingDirection)
{
	switch(shifttingDirection)
	{
		case LCD_SHIFT_RIGHT:
		LCD_sendCmnd(0b00011100);  //LCD_sendCmnd(0x28);
		_delay_us(45);
		break;
		
		case LCD_SHIFT_LEFT:
		LCD_sendCmnd(0b00011000);  //LCD_sendCmnd(0x22);
		_delay_us(45);
		break;
	}
}

void LCD_goToSpecification(u8 LineNumber,u8 position)
{
	switch(LineNumber)
	{
		case LCD_LINE_ONE:
		LCD_sendCmnd(0x80+position);
		_delay_us(45);
		break;
		
		case LCD_LINE_TWO:
		LCD_sendCmnd(0xc0+position);
		_delay_us(45);
		break;
	}
}

void LCD_WriteNumber(u32 number)//75
{
	u32 ReverseNum=1;
	if (number==0)
	{
		LCD_sendChar('0');
		return;
	}
	else
	{
		//reverse the number
		while(number!=0)
		{
			ReverseNum=ReverseNum*10 + number%10;//10+5=15 round 2>>(15*10)=150+7=157
			number=number/10;//7
		}
		do 
		{
			LCD_sendChar(ReverseNum%10+'0');
			ReverseNum=ReverseNum/10;
		} while (ReverseNum!=1);
	}
}

void LCD_clear(void)
{
	//Clear Display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
}