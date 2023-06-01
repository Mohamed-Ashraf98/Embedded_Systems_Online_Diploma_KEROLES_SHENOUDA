#include "TM4C123.h"

/* ------------------------------------------------------------ */

volatile R_SYSCTL_RCGC2_t *SYSCTL_RCGC2       = (volatile R_SYSCTL_RCGC2_t *)(SYSCTL_BASE + 0x108);
volatile R_GPIO_PORTF_DEN_t *GPIO_PORTF_DEN   = (volatile R_GPIO_PORTF_DEN_t *)(GPIOF_BASE + 0x51C);
volatile R_GPIO_PORTF_DIR_t *GPIO_PORTF_DIR   = (volatile R_GPIO_PORTF_DIR_t *)(GPIOF_BASE + 0x400);
volatile R_GPIO_PORTF_DATA_t *GPIO_PORTF_DATA = (volatile R_GPIO_PORTF_DATA_t *)(GPIOF_BASE + 0x3FC);

/* ------------------------------------------------------------ */

int main()
{
    vuint32_t delay_count = 0;

    /* enable GPIO Port_F */
    SYSCTL_RCGC2->all_ports = 0x00000020;

    /* delay to make sure that GPIO is up and running */
    for(delay_count = 0; delay_count < 200; delay_count++);

    /* enable GPIO Port_F pin 3 */
    GPIO_PORTF_DEN->pin3 = 1;

    /* set GPIO Port_F pin 3 as output */
    GPIO_PORTF_DIR->pin3 = 1;

    /* 1/0 output from GPIO Port_F pin3 */
    while(1)
    {
        GPIO_PORTF_DATA->pin3 = 1;        /* output : 1 , LED is ON */
        for(delay_count = 0; delay_count < 200000; delay_count++);    /* delay */

        GPIO_PORTF_DATA->pin3 = 0;        /* output : 0 , LED is OFF */
        for(delay_count = 0; delay_count < 200000; delay_count++);    /* delay */
    }

    return 0;
}