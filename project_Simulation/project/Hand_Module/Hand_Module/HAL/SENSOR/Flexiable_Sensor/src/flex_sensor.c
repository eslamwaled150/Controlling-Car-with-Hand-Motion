/*
 * module name: 	 flex_sensor (Flexible Sensor)
 * file name :       flex_sensor_types.c
 * file description: this file contains flexible sensor implementation of function of this module
 * version: 		 v01
 * date:    		 16/3/2024
 * author:  		 Salma Motaz
 */ 


#include "flex_sensor.h"

void HFlexSensor_vidInit(STD_ADC_InitType * cpy_STDOption)		//function to set ADC option
{
	MADC_vidInit(cpy_STDOption);
}

f32 HFlexSensor_u16AnalogRead(ENUM_ADC_ChannelTypes cpy_enumChannelType)		//function to read resistance value of the flexible sensor
{
	u16 loc_u16ADCValue = STD_Low; 
	f32 loc_u16FlexVolt = STD_Low, loc_u16FlexRes = STD_Low;	
	loc_u16ADCValue = MADC_u16Read(cpy_enumChannelType);						//read digital value of ADC for reading
	loc_u16FlexVolt = (loc_u16ADCValue * FLEX_SENSOR_VIN) / ADC_Resoluton;		//calculate voltage value of flexible sensor 
	if(STD_Low == loc_u16FlexVolt)												//if flex sensor did not work return base resistance of flexible sensor
	{
		loc_u16FlexRes = 970;
	}
	else
	{
		loc_u16FlexRes = Res_DIV_In_OHM *(FLEX_SENSOR_VIN/loc_u16FlexVolt - 1);		//calculate resistance value
	}
	
	return loc_u16FlexRes;
}

u8 HFlexSensor_u16DigitalRead(DIO_ChannelTypes cpy_enumChannelId)		//function use in simulation only to read digital fleible sensor in simulation
{
	u8 loc_u16FlexState = STD_Low; 
	loc_u16FlexState = MDIO_vidReadChannel(cpy_enumChannelId);
	return(loc_u16FlexState);
}
