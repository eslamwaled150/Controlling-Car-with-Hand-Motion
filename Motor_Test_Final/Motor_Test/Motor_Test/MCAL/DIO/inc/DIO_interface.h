/*
 * DIO_interface.h
 *
 *  Created on: Dec 31, 2022
 *      Author: AMIT
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Clock.h"

             /*************** MACROS FOR PIN ***************/
/* Macros For Pin Id */
#define DIO_PIN0           0
#define DIO_PIN1           1
#define DIO_PIN2           2
#define DIO_PIN3           3
#define DIO_PIN4           4
#define DIO_PIN5           5
#define DIO_PIN6           6
#define DIO_PIN7           7

/* Macros For Pin Direction */
#define DIO_PIN_INPUT      0
#define DIO_PIN_OUTPUT     1

/* Macros For Pin state */
#define DIO_PIN_LOW        0
#define DIO_PIN_HIGH       1


           /*************** MACROS FOR PORT ***************/

/* Macros For Port Id */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

/* Macros For Port Direction */
#define DIO_PORT_INPUT      0x00
#define DIO_PORT_OUTPUT     0xff

/* Macros For Port state */
#define DIO_PORT_LOW        0x00
#define DIO_PORT_HIGH       0xff


           /*************** APIS PROTO TYPES ***************/

void DIO_init(void);

/* Pin Apis */
void DIO_setPinDirection            (u8 PortId, u8 PinId, u8 PinDirection);
void DIO_setPinValue                (u8 PortId, u8 PinId, u8 PinValue);  //output on pin
void DIO_getPinValue                (u8 PortId, u8 PinId, u8* PinValue); //Input of PINS
void DIO_togglePinValue             (u8 PortId, u8 PinId);
void DIO_activePinInPullUpResistance(u8 PortId, u8 PinId);

/* Port Apis */	
void DIO_setPortDirection            (u8 PortId, u8 PortDirection);
void DIO_setPortValue                (u8 PortId, u8 PortValue);
void DIO_getPortValue                (u8 PortId, u8* PortValue);
void DIO_togglePortValue             (u8 PortId);
void DIO_activePortInPullUpResistance(u8 PortId);

#endif /* DIO_INTERFACE_H_ */
