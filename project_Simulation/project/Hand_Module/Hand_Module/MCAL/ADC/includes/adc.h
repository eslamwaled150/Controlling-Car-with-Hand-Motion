/*
 * module name: 	 ADC (Analog to digital converter)
 * file name :       adc.h
 * file description: this file contains ADC prototype of function of this module
 * version: 		 v01
 * date:    		 14/10/2023
 * author:  		 Salma Motaz
 */ 


#ifndef ADC_H_
#define ADC_H_

		/* library */
#include "std_types.h"

		/* MCAL */
#include "adc_reg.h"

void MADC_vidInit(STD_ADC_InitType * cpy_STDOption);
u16 MADC_u16Read(ENUM_ADC_ChannelTypes cpy_enumChannelType);

#endif /* ADC_H_ */