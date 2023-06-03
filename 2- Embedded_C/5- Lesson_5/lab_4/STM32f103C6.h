//#include "STM32f103C6.h"
#ifndef _STM32f103C6_H_
#define _STM32f103C6_H_

/* ------------------------------------------------------------ */

#include <stdlib.h>
#include "Platforms_Types.h"

/* ------------------------------------------------------------ */

#define RCC_BASE   0x40021000
#define GPIOA_BASE 0x40010800

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

#endif //_STM32f103C6_H_