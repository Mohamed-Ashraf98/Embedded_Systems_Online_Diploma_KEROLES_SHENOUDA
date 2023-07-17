/*
 =========================================================================================
 Name        : dc_motor.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Tue, Jun 13 2023
 time        :
 Description : state machine of collision avoidance in multiple modules , Ansi-style
 =========================================================================================
*/

#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_
/* ------------------Includes section------------------- */
#include "std_libraries.h"


/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */

/* DC Motor configurations enable/disable */
#define DC_MOTOR_CONFIG                     enable


/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

/**
  *  @brief   set the speed of the motor
  *  @param   (speed)       the speed of the motor passed by value
  */
void dc_motor_set_speed(int speed);


/* ----------------------------------------------------------------------------------- */
#endif //_DC_MOTOR_H_