#include "STM32f103C6.h"

/* ------------------------------------------------------------ */

volatile R_RCC_APB2ENR_t *RCC_APB2ENR = (volatile R_RCC_APB2ENR_t *)(RCC_BASE + 0x18);
volatile R_GPIOA_CRH_t *GPIOA_CRH = (volatile R_GPIOA_CRH_t *)(GPIOA_BASE + 0x04);
volatile R_GPIOA_ODR_t *GPIOA_ODR = (volatile R_GPIOA_ODR_t *)(GPIOA_BASE + 0x0C);

vuint8_t BSS_variable_1;
const uint8 RO_variable_1 = 10;

/* ------------------------------------------------------------ */

int main()
{
    vuint32_t i = 0;
    
    RCC_APB2ENR->pin2 = 1;

    GPIOA_CRH->pin20 = 0;
    GPIOA_CRH->pin21 = 1;
    GPIOA_CRH->pin22 = 0;
    GPIOA_CRH->pin23 = 0;

    while(1)
    {
        GPIOA_ODR->pin13 = 1;
        for(i = 0; i<5000; i++);   //delay

        GPIOA_ODR->pin13 = 0;
        for(i = 0; i<5000; i++);   //delay
    }

    return 0;
}