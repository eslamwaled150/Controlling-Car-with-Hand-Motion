/*
 * module name: 	 flex_sensor (Flexible Sensor)
 * file name :       flex_sensor.h
 * file description: this file contains flexible sensor prototype of function of this module
 * version: 		 v01
 * date:    		 16/3/2024
 * author:  		 Salma Motaz
 */ 


#ifndef LM35_H_
#define LM35_H_

	/* Library */
	
#include "std_types.h"

	/* MCAL */
#include "dio.h"
#include "adc.h"
	
	/* HAL */
#include "flex_sensor_types.h"

void HFlexSensor_vidInit(STD_ADC_InitType * cpy_STDOption);
f32 HFlexSensor_u16AnalogRead(ENUM_ADC_ChannelTypes cpy_enumChannelType);
u8 HFlexSensor_u16DigitalRead(DIO_ChannelTypes cpy_enumChannelId);

#endif /* LM35_H_ */