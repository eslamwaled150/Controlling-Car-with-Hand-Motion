/*
 * module name: 	 DIO_REG
 * file name :       dio_reg.h
 * file description: this file contains DIO register definition
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */


#ifndef DIO_REG_H_
#define DIO_REG_H_

	/* library */
#include "std_types.h"

/* register definition*/

#define	PORTA_reg	(*(volatile u8*)0x3B)	/* Port A Data Register */
#define	DDRA_reg	(*(volatile u8*)0x3A)	/* Port A Data Direction Register  */
#define	PINA_reg	(*(volatile u8*)0x39)	/* Port A Input Pins Address */

#define	PORTB_reg	(*(volatile u8*)0x38)	/* Port B Data Register */
#define	DDRB_reg	(*(volatile u8*)0x37)	/* Port B Data Direction Register  */
#define	PINB_reg	(*(volatile u8*)0x36)	/* Port B Input Pins Address */

#define	PORTC_reg	(*(volatile u8*)0x35)   /* Port C Data Register */
#define	DDRC_reg	(*(volatile u8*)0x34)   /* Port C Data Direction Register  */
#define	PINC_reg	(*(volatile u8*)0x33)   /* Port C Input Pins Address */

#define	PORTD_reg	(*(volatile u8*)0x32)	/* Port D Data Register */
#define	DDRD_reg	(*(volatile u8*)0x31)	/* Port D Data Direction Register  */
#define	PIND_reg	(*(volatile u8*)0x30)	/* Port D Input Pins Address */


#endif /* DIO_REG_H_ */