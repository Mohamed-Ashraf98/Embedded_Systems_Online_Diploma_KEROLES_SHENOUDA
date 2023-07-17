/*
 =========================================================================================
 Name        : obstical_avoidance.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Tue, Jun 13 2023
 time        :
 Description : state machine of collision avoidance in multiple modules , Ansi-style
 =========================================================================================
*/

#ifndef _OBSTICAL_AVOIDANCE_H_
#define _OBSTICAL_AVOIDANCE_H_
/* ------------------Includes section------------------- */
#include "ultra_sonic.h"
#include "dc_motor.h"


/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */

/* obstical avoidance configurations enable/disable */
#define AVOIDANCE_CONFIG                    enable


/* ----------------------------------------------------------------------------------- */
/* -------------------Global section-------------------- */
extern int OA_speed;                        /* holds the speed of the motor */
extern int OA_distance;                     /* holds the distance measured by ultrasonic sensor */
extern int threshold;                       /* the threshold compared with the distance measured by the ultrasonic sensor */


/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

/**
  *  @brief   waiting state
  *  @retval  (l_status)    status of the performed operation
  *                         (operation_fail)        when the operation fail
  *                         (operation_success)     when the operation performed successfully
  */
std_return_t obstical_avoidance_waiting(void);


/**
  *  @brief   driving state
  *  @retval  (l_status)    status of the performed operation
  *                         (operation_fail)        when the operation fail
  *                         (operation_success)     when the operation performed successfully
  */
std_return_t obstical_avoidance_driving(void);


/* ----------------------------------------------------------------------------------- */
#endif //_OBSTICAL_AVOIDANCE_H_