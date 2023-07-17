/*
 =========================================================================================
 Name        : main.c
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
/* ------------functions definition section------------- */
void _init(void)
{
    obstical_avoidance_waiting();
}


/* ----------------------------------------------------------------------------------- */

void main(void)
{
    /* initialization section */
    _init();

    /* looping */
    while(1)
    {
        if(OA_distance <= threshold)
        {
            obstical_avoidance_waiting();
        }
        else
        {
            obstical_avoidance_driving();
        }
    }
}