/*
 * STM32f103C6.h
 *
 *  Created on: May 13, 2023
 *      Author: Mohamed Ashraf
 */

#ifndef STM32F103C6_H_
#define STM32F103C6_H_

/* ------------------------------------------------------------ */

#include "Platforms_Types.h"

/* ------------------------------------------------------------ */

#define RCC_BASE   0x40021000
#define GPIOA_BASE 0x40021000

/* ------------------------------------------------------------ */

typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:2;
        vuint32_t pin2:1;
    };
}R_RCC_APB2ENR_t;


typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:20;
        vuint32_t pin20:1;
        vuint32_t pin21:1;
        vuint32_t pin22:1;
        vuint32_t pin23:1;
    };
}R_GPIOA_CRH_t;


typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:13;
        vuint32_t pin13:1;
    };
}R_GPIOA_ODR_t;

/* ------------------------------------------------------------ */

#endif /* STM32F103C6_H_ */
