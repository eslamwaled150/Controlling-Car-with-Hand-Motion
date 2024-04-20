/*
 * GIE.c
 *
 * Created: 4/19/2024 5:11:13 PM
 *  Author: Gebruiker
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GIE.h"



/* Function to enable global interrupt */
void GIE_Enable(void)
{
	SET_BIT(SREG_Reg,GIE_ENABLE_BIT);
}

/* Function to disable global interrupt */
void GIE_Disable(void)
{
	CLR_BIT(SREG_Reg,GIE_ENABLE_BIT);
}