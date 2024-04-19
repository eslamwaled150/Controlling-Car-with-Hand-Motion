/*
 * module name: 	 LCD (Liquid Crystal Display)
 * file name :       lcd.h
 * file description: this file contains DIO prototype of function of this module
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */


#ifndef LCD_H_
#define LCD_H_

/* library */
#include "clock.h"

/* MCAL */
#include "dio.h"

#define	LCD_RS			DIO_ChannelB1		/* Selecting LCD Register Select pin */
#define	LCD_RW			DIO_ChannelB2		/* Selecting LCD Read/write pin */
#define	LCD_E			DIO_ChannelB3		/* Selecting LCD Enable pin */

#define LCD_DataPort	DIO_PORTB			/* Define LCD data port direction */

void HLCD_vidInit();
void HLCD_vidSendCommend(u8 cpy_u8Commend);
void HLCD_vidSendChar (u8 cpy_u8Data);
void HLCD_vidSendString(s8* cpy_s8PTString);
void HLCD_vidSendNumber(s32 cpy_s32Number);
void HLCD_vidSendFloat(f64 cpy_f64Float);
void HLCD_vidSetPosition(u8 cp_u8Line, u8 cp_u8position);
void HLCD_vidCustomChar(u8 cpy_u8Location, s8 * cpy_s8PTMassaged);
void HLCD_vidClearScreen();



#endif /* LCD_H_ */