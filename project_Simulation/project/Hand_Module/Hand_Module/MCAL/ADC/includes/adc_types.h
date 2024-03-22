/*
 * module name: 	 ADC (Analog to digital converter)
 * file name :       adc_types.h
 * file description: this file contains ADC data types needed for this module
 * version: 		 v01
 * date:    		 14/10/2023
 * author:  		 Salma Motaz
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

#include "std_types.h"

typedef enum				/* enum of Analog Channel name */
{
	ADC_Channel0 = 0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,	
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ENUM_ADC_ChannelTypes;

typedef enum              /* enum of prescaler of ADC */
{
	ADC_Prescaler2 = 1,
	ADC_Prescaler4,
	ADC_Prescaler8,
	ADC_Prescaler16,
	ADC_Prescaler32,
	ADC_Prescaler64,
	ADC_Prescaler128		
}ENUM_ADC_PrescalerTypes;

typedef enum			/* enum of Reference voltage name */
{
	ADC_Vref_AREF = 0,	
	ADC_Vref_AVCC,
	ADC_Vref_Reserved,
	ADC_Vref_Internal
}ENUM_ADC_VrefTypes;

typedef struct
{
	ENUM_ADC_VrefTypes STD_adcVrefType;
	ENUM_ADC_PrescalerTypes STD_adcClock;
	
}STD_ADC_InitType;

typedef struct
{
	u8 ADPS_Bits : 3;		/* ADC Prescaler Select Bits */
	u8 ADIE_Bit : 1;		/* ADC Interrupt Enable */
	u8 ADIF_Bit : 1;		/* ADC Interrupt Flag */
	u8 ADATE_Bit : 1;		/* auto trigger enable*/
	u8 ADSC_Bit : 1;		/* ADC Start Conversion */
	u8 ADEN_Bit : 1;		/* ADC Enable */
}STD_ADC_ADCSRA_Bits;

typedef union						/*Union contain u8 variable and structure to access bit field of same union */
{
	u8 AllRegister;
	STD_ADC_ADCSRA_Bits Bits;
}STD_ADC_ADCSRA_Register;

typedef struct									/*Structure with registers name*/
{
	u8 ADCL_REG;								/* ADC High register*/
	u8 ADCH_REG;								/* ADC LOW register*/
	STD_ADC_ADCSRA_Register ADC_ADCSRA_REG;		/* ADC control and status register*/
	u8 ADCMUX_REG;								/*ADC multiplexer selection register*/
}STD_ADC_Registers;

#endif /* ADC_TYPES_H_ */