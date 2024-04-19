/*
 * module name: 	 ADC (Analog to digital converter)
 * file name :       adc.c
 * file description: this file contains ADC implementation of function of this module
 * version: 		 v01
 * date:    		 14/10/2023
 * author:  		 Salma Motaz
 */ 

#include "adc.h"

void MADC_vidInit(STD_ADC_InitType * cpy_STDOption)
{
	/*select the reference voltage */
	ADC_Registers -> ADCMUX_REG = (cpy_STDOption -> STD_adcVrefType ) << 6;
	
	/* Select the pre-scaler*/
	ADC_Registers -> ADC_ADCSRA_REG.AllRegister |= cpy_STDOption -> STD_adcClock;
	
	/*select the no auto trigger*/
	ADC_Registers -> ADC_ADCSRA_REG.Bits.ADATE_Bit = 0;
	
	/*enable the ADC*/
	ADC_Registers -> ADC_ADCSRA_REG.Bits.ADEN_Bit = 1;
}

u16 MADC_u16Read(ENUM_ADC_ChannelTypes cpy_enumChannelType)
{
	u16 loc_u16ADCValue = STD_Low;
	
	/*set multiplexer channel*/
	/* clear the first 5 bits a ADMUX register*/
	ADC_Registers -> ADCMUX_REG &= 0b11100000;
	ADC_Registers -> ADCMUX_REG |= (cpy_enumChannelType & 0b00011111);

	//ADC_Registers -> ADCMUX_REG |= (ADC_Registers -> ADCMUX_REG & 0b11100000) | (cpy_enumChannelType & 0b00011111);
	
	/* start conversion*/
	ADC_Registers -> ADC_ADCSRA_REG.Bits.ADSC_Bit = 1; //Start Conversion
	
	/* Waiting the flag */
	while(ADC_Registers -> ADC_ADCSRA_REG.Bits.ADIF_Bit == 0 ); 
	
	/*clear flag*/
	ADC_Registers -> ADC_ADCSRA_REG.Bits.ADIF_Bit = 1;
	
	/* Assemblage ADC value in single variable */
	loc_u16ADCValue = (ADC_Registers -> ADCL_REG) | (ADC_Registers -> ADCH_REG << 8);
	
	return loc_u16ADCValue;
}