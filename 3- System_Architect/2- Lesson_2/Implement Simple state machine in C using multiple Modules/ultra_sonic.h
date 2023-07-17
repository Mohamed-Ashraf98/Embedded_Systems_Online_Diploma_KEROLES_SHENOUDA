/*
 =========================================================================================
 Name        : ultra_sonic.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Tue, Jun 13 2023
 time        :
 Description : state machine of collision avoidance in multiple modules , Ansi-style
 =========================================================================================
*/

#ifndef _ULTRA_SONIC_H_
#define _ULTRA_SONIC_H_
/* ------------------Includes section------------------- */
#include "std_libraries.h"


/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */

/* ultra sonic configurations enable/disable */
#define US_SENSOR_CONFIG                    enable


/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

/**
  *  @brief   generate random values for the distance as its measured from sensor
  *  @param   (l)           minimum range for the random values
  *  @param   (r)           maximum range for the random values
  *  @param   (count)       number of generated random values
  *  @retval  (rand_num)    the generated random value
  */
int ultra_sonic_get_distance(int l ,int r ,int count);


/* ----------------------------------------------------------------------------------- */
#endif //_ULTRA_SONIC_H_