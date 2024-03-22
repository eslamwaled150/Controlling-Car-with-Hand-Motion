/*
 * module name: 	 DIO (Digital Input Output)
 * file name :       dio.h
 * file description: this file contains DIO prototype of function of this module
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */


#ifndef DIO_H_
#define DIO_H_

		/* library */
#include "std_types.h"
#include "bitmath.h"
		
		/* MCAL */
#include "dio_reg.h"
#include "dio_Types.h"
#include "dio_cfg.h"

void MDIO_vidWriteChannel(DIO_ChannelTypes cpy_enumChannelId, STD_LevelTypes cpy_enumLevel);
STD_LevelTypes MDIO_vidReadChannel(DIO_ChannelTypes cpy_enumChannelId);
void MDIO_vidConfigChannel(DIO_ChannelTypes cpy_enumChannelId, DIO_DirTypes cpy_enumDirection);
void MDIO_vidTogggleChannel(DIO_ChannelTypes cpy_enumChannelId);
u8 MDIO_u8ReadPort(DIO_PortTypes cpy_enumPortId);
void MDIO_vidWritePort(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue);
void MDIO_vidConfigPort(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue);
void MDIO_vidWriteChannelGroup(DIO_PortTypes cpy_enumPortId, u8 cpy_u8PortValue, u8 cpy_u8Mask);

#endif /* DIO_H_ */