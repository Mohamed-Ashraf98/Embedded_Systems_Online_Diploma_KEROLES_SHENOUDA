/*
 =========================================================================================
 Name        : dc_motor.c
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Tue, Jun 13 2023
 time        :
 Description : state machine of collision avoidance in multiple modules , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */
/* ------------------Includes section------------------- */
#include "dc_motor.h"


/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

/**
  *  @brief   set the speed of the motor
  *  @param   (speed)       the speed of the motor passed by value
  */
#if DC_MOTOR_CONFIG
void dc_motor_set_speed(int speed)
{
    printf("speed : %d\n",speed);
}
#endif