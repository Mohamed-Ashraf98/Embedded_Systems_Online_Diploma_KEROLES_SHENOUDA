/*
 =========================================================================================
 Name        : obstical_avoidance.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Mon, Jun 12 2023
 time        :
 Description : state machine of collision avoidance in one module , Ansi-style
 =========================================================================================
*/

#ifndef _OBSTICAL_AVOIDANCE_H_
#define _OBSTICAL_AVOIDANCE_H_
/* ------------------Includes section------------------- */
#include "std_libraries.h"


/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */
#define ZERO_INIT               0           /* initailization by zero */

#define disable                 0
#define enable                  1

/* obstical avoidance configurations enable/disable */
#define avoidance_config        enable


/* ----------------------------------------------------------------------------------- */
/* -----user_defined data type declaration section------ */
typedef enum{
    operation_fail = 0,
    operation_success
}std_return_t;


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