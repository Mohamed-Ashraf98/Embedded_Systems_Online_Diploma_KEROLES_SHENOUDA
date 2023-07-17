/*
 =========================================================================================
 Name        : obstical_avoidance.c
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
#include "obstical_avoidance.h"


/* ----------------------------------------------------------------------------------- */
/* -------------------Global section-------------------- */
int OA_speed = ZERO_INIT;                   /* holds the speed of the motor */
int OA_distance = ZERO_INIT;                /* holds the distance measured by ultrasonic sensor */
int threshold = 50;                         /* the threshold compared with the distance measured by the ultrasonic sensor */


/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

/**
  *  @brief   waiting state
  *  @retval  (l_status)    status of the performed operation
  *                         (operation_fail)        when the operation fail
  *                         (operation_success)     when the operation performed successfully
  */
#if AVOIDANCE_CONFIG
std_return_t obstical_avoidance_waiting(void)
{
    /* create a local variable to hod the status of the performed operation */
    std_return_t l_status = operation_fail;

    /* you are in the waiting state */
    printf("waiting state  >>  ");

    /* display the distance */
    printf("distance : %d  >>  ",OA_distance);

    /* set the speed of the motor */
    OA_speed = 0;
    dc_motor_set_speed(OA_speed);

    /* get the distance value from the ultrasonic sensor */
    OA_distance = ultra_sonic_get_distance(45,55,1);

    l_status = operation_success;

    return l_status;
}
#endif


/**
  *  @brief   driving state
  *  @retval  (l_status)    status of the performed operation
  *                         (operation_fail)        when the operation fail
  *                         (operation_success)     when the operation performed successfully
  */
#if AVOIDANCE_CONFIG
std_return_t obstical_avoidance_driving(void)
{
    /* create a local variable to hod the status of the performed operation */
    std_return_t l_status = operation_fail;

    /* you are in the driving state */
    printf("driving state  >>  ");

    /* display the distance */
    printf("distance : %d  >>  ",OA_distance);

    /* set the speed of the motor */
    OA_speed = 30;
    dc_motor_set_speed(OA_speed);

    /* get the distance value from the ultrasonic sensor */
    OA_distance = ultra_sonic_get_distance(45,55,1);

    l_status = operation_success;

    return l_status;
}
#endif

/* ----------------------------------------------------------------------------------- */