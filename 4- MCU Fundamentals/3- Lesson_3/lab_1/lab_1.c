/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */

/* base address of GPIOA is 0x40010800 */
#define GPIOA_BASE      0x40010800

/* offset of port configuration register high (GPIOx_CRH) is 0x04 */
#define GPIOA_CRH       *(volatile unsigned int *)(GPIOA_BASE + 0x04)

/* offset of port output data register (GPIOx_ODR) is 0x0C */
#define GPIOA_ODR       *(volatile unsigned int *)(GPIOA_BASE + 0x0C)

/* ---------------------------------------- */

/* base address of Reset and clock control RCC is 0x40021000 */
#define RCC_BASE        0x40021000

/* offset of APB2 peripheral clock enable register (RCC_APB2ENR) is 0x18 */
#define RCC_APB2ENR     *(volatile unsigned int *)(RCC_BASE + 0x18)

/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

void __init(void);

/* ----------------------------------------------------------------------------------- */

int main()
{
    /* local variable for the delay */
    volatile unsigned int delay_counter = 0;

    /* initialization */
    __init();

    /* looping */
    while(1)
    {
        /* write logic 1 in pin 13 in PORTA */
        GPIOA_ODR |= 1<<13;

        /* arbitrary delay */
        for(delay_counter = 0; delay_counter < 5000; delay_counter++);

        /* write logic 0 in pin 13 in PORTA */
        GPIOA_ODR &= ~(1<<13);

        /* arbitrary delay */
        for(delay_counter = 0; delay_counter < 5000; delay_counter++);
    }

    return 0;
}

/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

void __init(void)
{
    /* GPIOA clock init */
    /*
        Bit 2 IOPAEN: IO port A clock enable
            Set and cleared by software.
            0: IO port A clock disabled
            1: IO port A clock enabled
    */
    RCC_APB2ENR |= 1<<2;
    

    /* Bit 23:22 in CRH Register */
    /*
        In output mode (MODE[1:0] > 00):
        00: General purpose output push-pull
    */
    
    /* Bit 21:20 in CRH Register */
    /* 10: Output mode, max speed 2 MHz. */

    /* Bit 23:20 will be 0010 (0x2) */
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
}