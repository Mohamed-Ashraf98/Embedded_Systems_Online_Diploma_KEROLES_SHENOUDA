//#include "TM4C123.h"
#ifndef _TM4C123_H_
#define _TM4C123_H_

/* --------------------------------------------------------------------------- */

#include "Platforms_Types.h"

/* --------------------------------------------------------------------------- */

/* System Control >> start address : 0x400FE000 , end address : 0x400FEFFF */
/* GPIO Port F    >> start address : 0x40025000 , end address : 0x40025FFF */

#define GPIOF_BASE   0x40025000
#define SYSCTL_BASE  0x400FE000

/* --------------------------------------------------------------------------- */

/* Enable the GPIO port */
typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:4;
        vuint32_t _GPIOPort_F_Enable:4;  /* enable GPIO Port_F */
    };
}R_SYSCTL_RCGC2_t;


/* Enable the GPIO Port_F pins */
typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:3;
        vuint32_t pin3:1;                /* enable GPIO Port_F pin 3 */
    };
}R_GPIO_PORTF_DEN_t;


/* set the GPIO Port_F pins as output or input */
typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:3;
        vuint32_t pin3:1;                /* set GPIO Port_F pin 3 as output */
    };
}R_GPIO_PORTF_DIR_t;


/* GPIO Port_F DATA Register */
typedef union {
    vuint32_t all_ports;
    struct{
        vuint32_t reserved:3;
        vuint32_t pin3:1;                /* 1/0 output from GPIO Port_F pin3 */
    };
}R_GPIO_PORTF_DATA_t;

/* --------------------------------------------------------------------------- */

#endif //_TM4C123_H_