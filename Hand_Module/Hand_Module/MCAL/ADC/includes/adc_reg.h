/*
 * module name: 	 ADC (Analog to digital converter)
 * file name :       adc_reg.h
 * file description: this file contains ADC register 
 * version: 		 v01
 * date:    		 14/10/2023
 * author:  		 Salma Motaz
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_


#include "adc_types.h"

/* register definition*/

#define ADC_Registers (( volatile STD_ADC_Registers* ) 0x24 )

#endif /* ADC_REG_H_ */