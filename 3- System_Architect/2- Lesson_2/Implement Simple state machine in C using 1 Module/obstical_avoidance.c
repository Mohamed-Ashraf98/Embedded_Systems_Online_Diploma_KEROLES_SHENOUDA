/*
 =========================================================================================
 Name        : obstical_avoidance.c
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Mon, Jun 12 2023
 time        :
 Description : state machine of collision avoidance in one module , Ansi-style
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

static int generate_random(int l ,int r ,int count)
{
    int i = ZERO_INIT;
    int rand_num = ZERO_INIT;

    for(i = 0; i < count; i++)
    {
        rand_num = ( rand() % (r - l + 1) ) + l;
    }
    return rand_num;
}


void dc_motor_set_speed(int speed)
{
    printf("speed : %d\n",speed);
}


/**
  *  @brief   waiting state
  *  @retval  (l_status)    status of the performed operation
  *                         (operation_fail)        when the operation fail
  *                         (operation_success)     when the operation performed successfully
  */
#if avoidance_config
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
    OA_distance = generate_random(45,55,1);

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
#if avoidance_config
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
    OA_distance = generate_random(45,55,1);

    l_status = operation_success;

    return l_status;
}
#endif

/* ----------------------------------------------------------------------------------- */