/************************************************************************
 *                                                                      *
 *************************  Date    : 23/07/2023      *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : DIO             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef DIO_private_K_
#define DIO_private_K_


                                        /* DIO REGISTERS*/
								 
/* DATA DIRCTION REGISTERS */
#define DDRA           (*(volatile u8*)0x3A)
#define DDRB           (*(volatile u8*)0x37)
#define DDRC           (*(volatile u8*)0x34)
#define DDRD           (*(volatile u8*)0x31)

/* OUTPUT REGISTERS */
#define PORTA          (*(volatile u8*)0x3B)
#define PORTB          (*(volatile u8*)0x38)
#define PORTC          (*(volatile u8*)0x35)
#define PORTD          (*(volatile u8*)0x32)

/* INPUT REGISTERS */
#define PINA           (*(volatile u8*)0x39)
#define PINB           (*(volatile u8*)0x36)
#define PINC           (*(volatile u8*)0x33)
#define PIND           (*(volatile u8*)0x30)


/* Macros For Pins Initial Directions */

#define DIO_INITIAL_INPUT               0
#define DIO_INITIAL_OUTPUT              1

/* Macros For Pins Initial Values */

#define DIO_INITIAL_INPUT_FLOATING      0
#define DIO_INITIAL_INPUT_PULLUP        1
#define DIO_INITIAL_OUTPUT_LOW          0	
#define DIO_INITIAL_OUTPUT_HIGH	        1   
   
/* Macros For Concatenation Functions */

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)        CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /*DIO_private_K_*/