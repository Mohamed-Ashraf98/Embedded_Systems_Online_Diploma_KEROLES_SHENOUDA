/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "STM32f103C6.h"

/* ------------------------------------------------------------ */

volatile R_RCC_APB2ENR_t *RCC_APB2ENR = (volatile R_RCC_APB2ENR_t *)(RCC_BASE + 0x18);
volatile R_GPIOA_CRH_t *GPIOA_CRH = (volatile R_GPIOA_CRH_t *)(GPIOA_BASE + 0x04);
volatile R_GPIOA_ODR_t *GPIOA_ODR = (volatile R_GPIOA_ODR_t *)(GPIOA_BASE + 0x0C);

/* ------------------------------------------------------------ */

int main()
{
    RCC_APB2ENR->pin2 = 1;

    GPIOA_CRH->pin20 = 0;
    GPIOA_CRH->pin21 = 1;
    GPIOA_CRH->pin22 = 0;
    GPIOA_CRH->pin23 = 0;

    while(1)
    {
        GPIOA_ODR->pin13 = 1;
        for(int i = 0; i<5000; i++);   //delay

        GPIOA_ODR->pin13 = 0;
        for(int i = 0; i<5000; i++);   //delay
    }

    return 0;
}
