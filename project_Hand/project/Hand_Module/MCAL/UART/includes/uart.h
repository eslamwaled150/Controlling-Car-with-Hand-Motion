/*
 * uart.h
 *
 * Created: 11/3/2023 11:22:34 A
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL
#include "UART_reg.h"

void UART_init    (void);
void UART_TxChar  (u8 TxData);
u8 UART_RxChar();

#endif /* UART_H_ */