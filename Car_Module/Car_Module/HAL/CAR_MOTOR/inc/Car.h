/*
 * Car.h
 *
 * Created: 3/21/2024 10:25:42 AM
 *  Author: Omar
 */ 

#include "STD_TYPES.h"

#ifndef CAR_H_
#define CAR_H_

void CarMotor_init          (void);
void CarMotor_Stop          (u8 SpeedRange);
void CarMotor_forward       (u8 SpeedRange);
void CarMotor_backword      (u8 SpeedRange);
void CarMotor_toRight       (u8 SpeedRange);
void CarMotor_toLeft        (u8 SpeedRange);



#endif /* CAR_H_ */