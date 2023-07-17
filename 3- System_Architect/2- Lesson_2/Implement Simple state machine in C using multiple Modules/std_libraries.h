/*
 =========================================================================================
 Name        : std_libraries.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Tue, Jun 13 2023
 time        :
 Description : standard libraries , Ansi-style
 =========================================================================================
*/

#ifndef _STD_LIBRARIES_H_
#define _STD_LIBRARIES_H_
/* ------------------Includes section------------------- */
#include <stdio.h>
#include <stdlib.h>


/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */
#define ZERO_INIT                           0           /* initailization by zero */

#define disable                             0
#define enable                              1


/* ----------------------------------------------------------------------------------- */
/* -----user_defined data type declaration section------ */
typedef enum{
    operation_fail = 0,
    operation_success
}std_return_t;


/* ----------------------------------------------------------------------------------- */
#endif //_STD_LIBRARIES_H_