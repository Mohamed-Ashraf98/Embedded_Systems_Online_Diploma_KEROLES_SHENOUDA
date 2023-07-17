/*
 =========================================================================================
 Name        : ultra_sonic.c
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
#include "ultra_sonic.h"


/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

/**
  *  @brief   generate random values for the distance as its measured from sensor
  *  @param   (l)           minimum range for the random values
  *  @param   (r)           maximum range for the random values
  *  @param   (count)       number of generated random values
  *  @retval  (rand_num)    the generated random value
  */
#if US_SENSOR_CONFIG
int ultra_sonic_get_distance(int l ,int r ,int count)
{
    int i = ZERO_INIT;
    int rand_num = ZERO_INIT;

    for(i = 0; i < count; i++)
    {
        rand_num = ( rand() % (r - l + 1) ) + l;
    }
    return rand_num;
}
#endif