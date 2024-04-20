/*
 * GIE.h
 *
 * Created: 4/19/2024 5:11:39 PM
 *  Author: Gebruiker
 */ 


#ifndef GIE_H_
#define GIE_H_


#include "GIE_reg.h"
#include "GIE_types.h"

/* Function to enable global interrupt */
void GIE_Enable(void);

/* Function to disable global interrupt */
void GIE_Disable(void);


#endif /* GIE_H_ */