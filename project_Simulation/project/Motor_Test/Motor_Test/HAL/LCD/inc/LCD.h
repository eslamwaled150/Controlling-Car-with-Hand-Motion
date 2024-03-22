/*
 * LCD.h
 *
 * Created: 3/6/2024 6:13:38 PM
 *  Author: eslam
 */ 


#ifndef LCD_H_
#define LCD_H_

//Macros for LCD Shiftting Directions
#define LCD_SHIFT_LEFT              1
#define LCD_SHIFT_RIGHT             2 

//Macros For LCD Line ID 
#define LCD_LINE_ONE                1
#define LCD_LINE_TWO                2
 

void LCD_init             (void);
void LCD_sendCmnd         (u8 cmnd);
void LCD_sendChar         (u8 data);
void LCD_clear            (void);
void LCD_writeString      (u8* string);
void LCD_shift            (u8 shifttingDirection);
void LCD_goToSpecification(u8 LineNumber,u8 position);
void LCD_WriteNumber      (u32 number); //convert int to string


#endif /* LCD_H_ */