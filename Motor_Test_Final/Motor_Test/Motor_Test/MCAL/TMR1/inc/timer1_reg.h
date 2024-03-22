/*
 * timer1_reg.h
 *
 * Created: 3/19/2024 4:44:30 PM
 *  Author: Omar
 */ 


#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

// Timer/Counter1 Control Register A
#define TCCR1A             (*(volatile u8*)0x4F)
#define WGM10              0
#define WGM11              1
#define FOC1B              2
#define FOC1A              3
#define COM1B0             4
#define COM1B1             5
#define COM1A0             6
#define COM1A1             7

// Timer/Counter1 Control Register B
#define TCCR1B             (*(volatile u8*)0x4E)
#define CS10               0
#define CS11               1
#define CS12               2
#define WGM12              3
#define WGM13              4
#define ICES1              6
#define ICNC1              7

// Timer/Counter1
#define TCNT1_u16          (*(volatile u16*)0x4C)

// Output Compare Register 1 A
#define OCR1A_u16          (*(volatile u16*)0x4A)

// Output Compare Register 1 B
#define OCR1B_u16          (*(volatile u16*)0x48)

// Input Capture Register 1
#define ICR1_u16           (*(volatile u16*)0x46)



#endif /* TIMER1_REG_H_ */