#include "STM32f103C6.h"

/* ------------------------------------------------------------ */

volatile R_RCC_APB2ENR_t *RCC_APB2ENR = (volatile R_RCC_APB2ENR_t *)(RCC_BASE + 0x18);
volatile R_GPIOA_CRH_t   *GPIOA_CRH = (volatile R_GPIOA_CRH_t *)(GPIOA_BASE + 0x04);
volatile R_GPIOA_ODR_t   *GPIOA_ODR = (volatile R_GPIOA_ODR_t *)(GPIOA_BASE + 0x0C);

/* ------------------------------------------------------------ */

int main()
{
    vuint32_t i =0;
    
    RCC_APB2ENR->pin2 = 1;

    GPIOA_CRH->pin20 = 0;
    GPIOA_CRH->pin21 = 1;
    GPIOA_CRH->pin22 = 0;
    GPIOA_CRH->pin23 = 0;

    while(1)
    {
        GPIOA_ODR->pin13 = 1;          /* output : 1 , LED is ON */
        for(i = 0; i<5000; i++);   /* delay */

        GPIOA_ODR->pin13 = 0;          /* output : 0 , LED is OFF */
        for(i = 0; i<5000; i++);   /* delay */
    }

    return 0;
}