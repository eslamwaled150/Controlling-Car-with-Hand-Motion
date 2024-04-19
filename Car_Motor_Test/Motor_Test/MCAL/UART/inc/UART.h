/*
 * UART_interface.h
 *
 * Created: 11/3/2023 11:22:03 AM
 *  Author: Kareem Huseein
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include "UART_reg.h"

void UART_init    (void);  
void UART_TxChar  (u8 TxData);
void UART_RxChar(u8 *RxData);
void UART_RXC_EnableInt(void);
void UART_RXC_DisableInt(void);
void UART_RXC_SetCallback( void (*CopyFuncPtr) (void));


#endif /* UART_INTERFACE_H_ */