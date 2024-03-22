/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART.h"
#include "UART_reg.h"


void UART_init(void)
{ 
	/*************** USART CONFIG ***************
	 * NORMAL ASYNCHRONOUS MODE
	 * NO PARITY
	 * 8-BIT DATA MODE
	 * NO POLARITY
	 * ONE STOP BIT
	 * NO RECEIVE & TRANSIMT & UDR EMPTY INTERRUPTS
	 ********************************************/
	
	/************* UCSRB Description ************
	 * RXCIE = 0
	 * TXCIE = 0
	 * UDRIE = 0 
	 * RXEN  = 1
	 * TXEN  = 1
	 * UCSZ2 = 0
	 * PXB8 NOT USED FOR 8-BIT DATA MODE 
	 * TXB8 NOT USED FOR 8-BIT DATA MODE
	*********************************************/
	// Disable Rx complete interrupt
	CLR_BIT(UCSRB,RXCIE);
	
	// Disable Tx complete interrupt
	CLR_BIT(UCSRB,TXCIE);
	
	// Disable UDR empty interrupt
	CLR_BIT(UCSRB,UDRIE);

	//Enable Tx
	SET_BIT(UCSRB,TXEN);
	
	//Enable Rx
	SET_BIT(UCSRB,RXEN);
	//8-BIT MODE UCSZ2=0 UCSZ1=1 UCSZ0=1 
	CLR_BIT(UCSRB,UCSZ2);
	 
	/************* UCSRC Description ************
	 * URSEL = 1
	 * UMSEL = 0
	 * UPM1  = 0--|
	              |-->
	 * UPM0  = 0--|
	 * USBS  = 0
	 * UCSZ1 = 1--|
                  |-->     	 
	 * UCSZ0 = 1--|
	 * UCPOL = 0
	*********************************************/ 	
	

	// writing the UCSRC
	SET_BIT(UCSRC,URSEL);
	
	// select UART MODE = Asynchronous
	CLR_BIT(UCSRC,UMSEL);
	
	// configure no parity
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	
	// configure stop bits = 1
	CLR_BIT(UCSRC,USBS);
	
	//8-BIT MODE UCSZ2=0 UCSZ1=1 UCSZ0=1
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	//CLR_BIT(UCSRB,UCSZ2); DONE BEFORE 
	
	// configure no polarity
	CLR_BIT(UCSRC,UCPOL);
	
	//NORMAL ASYNCHRONUOS USART CONTROL & STATUS REG. A | U2X BIT -> 0 
	CLR_BIT(UCSRA,U2X);
	UBRRL = Buad_PreScale;
	UBRRH = Buad_PreScale>>8;	
	
}


void UART_TxChar(u8 TxData)
{
	// Busy Wait on Data Register empty flag
	while(0 == GET_BIT(UCSRA,UDRE));
	
	UDR = TxData;
	}


u8 UART_RxChar()
{
	
		u8 RxData;
		// Busy Wait on Receive Complete flag
		while(0 == GET_BIT(UCSRA,RXC));
		
		RxData = UDR;
		return RxData;
	
}















