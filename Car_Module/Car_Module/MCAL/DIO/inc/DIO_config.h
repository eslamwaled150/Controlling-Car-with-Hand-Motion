/************************************************************************
 *                                                                      *
 *************************  Date    : 23/07/2023      *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : DIO             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef DIO_config_K_
#define DIO_config_K_



                      /* MACROS FOR PINS INITIALIZATION */
					  
/* Options FOR Pins Initial Directions:
1- DIO_INITIAL_OUTPUT 
2- DIO_INITIAL_INPUT 
 */

#define DIO_PA0_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA1_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA2_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA3_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA4_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA5_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA6_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PA7_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
													 
#define DIO_PB0_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PB1_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PB2_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PB3_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PB4_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PB5_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PB6_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PB7_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
													  
#define DIO_PC0_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC1_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC2_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC3_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC4_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC5_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC6_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PC7_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
													 
#define DIO_PD0_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PD1_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PD2_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PD3_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PD4_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PD5_INITIAL_DIRECTION                     DIO_INITIAL_OUTPUT
#define DIO_PD6_INITIAL_DIRECTION                     DIO_INITIAL_INPUT
#define DIO_PD7_INITIAL_DIRECTION                     DIO_INITIAL_INPUT



/* Options FOR Pins Initial Values:
1- DIO_INITIAL_OUTPUT_HIGH 
2- DIO_INITIAL_OUTPUT_LOW   
3- DIO_INITIAL_INPUT_PULLUP
4- DIO_INITIAL_INPUT_FLOATING	  
 */

#define DIO_PA0_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PA1_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PA2_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_HIGH 
#define DIO_PA3_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW 
#define DIO_PA4_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PA5_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PA6_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PA7_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
											  
#define DIO_PB0_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PB1_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PB2_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PB3_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PB4_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PB5_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PB6_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PB7_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
											  
#define DIO_PC0_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC1_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC2_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PC3_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC4_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC5_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC6_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PC7_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
											  
#define DIO_PD0_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PD1_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PD2_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PD3_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PD4_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PD5_INITIAL_VALUE                 DIO_INITIAL_OUTPUT_LOW
#define DIO_PD6_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING
#define DIO_PD7_INITIAL_VALUE                 DIO_INITIAL_INPUT_FLOATING

#endif /*DIO_config_K_*/