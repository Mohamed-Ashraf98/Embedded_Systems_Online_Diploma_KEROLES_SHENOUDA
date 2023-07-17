/*
 =========================================================================================
 Name        : static_stack_ds_cfg.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Wed, Jun 7 2023
 time        :
 Description : control the configurations of the stack , Ansi-style
 =========================================================================================
*/

#ifndef _STATIC_STACK_DS_CFG_H_
#define _STATIC_STACK_DS_CFG_H_
/* ----------------------------------------------------------------------------------- */

/* --------------Macro definition section--------------- */

/* set the maximum number of elements inside the stack */
#define STACK_MAX_SIZE                 5

/* standard enable/disable */
#define DISABLE                        0
#define ENABLE                         1

/* debug enable/disable */
#define DEBUG_ENABLE                   DISABLE

/* control the stack configurations */
#define STACK_CONFIG                   ENABLE

/* ----------------------------------------------------------------------------------- */
#endif //_STATIC_STACK_DS_CFG_H_