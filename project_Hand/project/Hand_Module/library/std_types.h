/*
 * module name: 	 STD_TYPES (standard types)
 * file name :       std_types.h
 * file description: this file contains standard types of data types
 * version: 		 v03
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned           char      u8;
typedef unsigned short     int  	 u16;
typedef unsigned long  	   int       u32;
/*typedef unsigned         int       lu32; */
typedef unsigned long long int       u64;

//typedef signed   char				 s8;
typedef char				 s8;
typedef signed   short int 	         s16;
typedef signed 	 long  int		     s32;
/*typedef signed       int			 ls32;  */
typedef signed   long long int       s64;

typedef float                        f32;
typedef double                       f64;
typedef long double                  f128;

#define NULL			((void*)0X00)
#define STD_Error		0
#define STD_Sucesses	1

typedef enum
{
	STD_Low = 0,
	STD_High
}STD_LevelTypes;

#endif /* STD_TYPES_H_ */