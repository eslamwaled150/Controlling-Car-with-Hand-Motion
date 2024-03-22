/*
 * module name: 	 BIT_maths
 * file name :       bit_maths.h
 * file description: this file contains bit_ maths library
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */


#ifndef BITMATH_H_
#define BITMATH_H_

//function like macro
#define SET_BIT(Reg, bit_number) (Reg |= (1<<bit_number))
#define CLEAR_BIT(Reg, bit_number) (Reg &= ~(1<<bit_number))
#define TOGGLE_BIT(Reg, bit_number) (Reg ^= (1<<bit_number))
#define GET_BIT(Reg, bit_number) ((Reg>>bit_number) & 1)
//#define  GET_BIT(Reg, bit_number)		(((Reg & (1<<bit_number))>> bit_number)

#endif /* BITMATH_H_ */