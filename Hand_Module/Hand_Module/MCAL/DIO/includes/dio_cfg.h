/*
 * module name: 	 DIO (Digital Input Output)
 * file name :       dio_cfg.h
 * file description: this file contains DIO data types needed for this module
 * version: 		 v01
 * date:    		 29/9/2023
 * author:  		 Salma Motaz
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "dio.h"

typedef struct
{
	DIO_DirTypes STD_Direction;
	STD_LevelTypes STD_Level;
}DIO_PinCfg;

#define PINCOUNT	32

void MDIO_vidInit();

#endif /* DIO_CFG_H_ */