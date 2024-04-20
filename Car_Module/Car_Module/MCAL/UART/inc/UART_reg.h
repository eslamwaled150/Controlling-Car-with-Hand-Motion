/** *******UART_reg.h******* **/

#ifndef UART_reg_H_
#define UART_reg_H_

#define USART_BaudRate  9600  //buadrate of bluetooth module
#define Buad_PreScale   (((F_CPU/(USART_BaudRate * 16UL)))-1) //equation to calculate the value to be assigned to baud rate registers
/* UART REGISTERS*/

// USART I/O Data Register
#define UDR             (*(volatile u8*)0x2C)

// USART Control and Status Register A
#define UCSRA           (*(volatile u8*)0x2B)
#define MPCM             0
#define U2X              1//
#define PE               2
#define DOR              3
#define FE               4
#define UDRE             5//
#define TXC              6
#define RXC              7

// USART Control and Status Register B
#define UCSRB           (*(volatile u8*)0x2A)
#define TXB8             0
#define RXB8             1
#define UCSZ2            2//
#define TXEN             3
#define RXEN             4
#define UDRIE            5
#define TXCIE            6
#define RXCIE            7

// USART Control and Status Register C
#define UCSRC           (*(volatile u8*)0x40)
#define UCPOL           0
#define UCSZ0           1
#define UCSZ1           2
#define USBS            3
#define UPM0            4
#define UPM1            5
#define UMSEL           6
#define URSEL           7

// USART Baud Rate Registers
#define UBRRL           (*(volatile u8*)0x29)
#define UBRRH           (*(volatile u8*)0x40)


#endif /* UART_PRIVATE_H_ */