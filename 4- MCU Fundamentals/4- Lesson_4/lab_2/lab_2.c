/* ----------------------------------------------------------------------------------- */
/* --------------Macro definition section--------------- */

/* base address of Reset and clock control RCC is 0x40021000 */
#define RCC_BASE        0x40021000

/* offset of Clock control register (RCC_CR) is 0x00 */
#define RCC_CR          *(volatile unsigned int *)(RCC_BASE + 0x00)

/* offset of Clock configuration register (RCC_CFGR) is 0x04 */
#define RCC_CFGR        *(volatile unsigned int *)(RCC_BASE + 0x04)

/* offset of APB2 peripheral clock enable register (RCC_APB2ENR) is 0x18 */
#define RCC_APB2ENR     *(volatile unsigned int *)(RCC_BASE + 0x18)

/* ---------------------------------------- */

/* base address of GPIOA is 0x40010800 */
#define GPIOA_BASE      0x40010800

/* offset of Port configuration register low (GPIOx_CRL) is 0x00 */
#define GPIOA_CRL       *(volatile unsigned int *)(GPIOA_BASE + 0x00)

/* offset of port configuration register high (GPIOx_CRH) is 0x04 */
#define GPIOA_CRH       *(volatile unsigned int *)(GPIOA_BASE + 0x04)

/* offset of port output data register (GPIOx_ODR) is 0x0C */
#define GPIOA_ODR       *(volatile unsigned int *)(GPIOA_BASE + 0x0C)

/* ---------------------------------------- */

/* base address of AFIO is 0x40010000 */
#define AFIO_BASE       0x40010000

/* offset of External interrupt configuration register 1 (AFIO_EXTICR1) is 0x08 */
#define AFIO_EXTICR1    *(volatile unsigned int *)(AFIO_BASE + 0x08)

/* ---------------------------------------- */

/* base address of EXTI is 0x40010400 */
#define EXTI_BASE       0x40010400

/* offset of Interrupt mask register (EXTI_IMR) is 0x00 */
#define EXTI_IMR        *(volatile unsigned int *)(EXTI_BASE + 0x00)

/* offset of Rising trigger selection register (EXTI_RTSR) is 0x08 */
#define EXTI_RTSR       *(volatile unsigned int *)(EXTI_BASE + 0x08)

/* offset of Pending register (EXTI_PR) is 0x14 */
#define EXTI_PR         *(volatile unsigned int *)(EXTI_BASE + 0x14)

/* ---------------------------------------- */

/* base address of NVIC is 0xE000E100 */
#define NVIC_BASE       0xE000E100

/* offset of interrupt set-enable register (NVIC_ISER0) is 0x00 */
#define NVIC_ISER0         *(volatile unsigned int *)(NVIC_BASE + 0x00)

/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

void __init(void);

/* ----------------------------------------------------------------------------------- */

int main()
{
    /* initialization */
    __init();

    /* looping */
    while(1)
    {
        
    }

    return 0;
}

/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

void __init(void)
{
    /* ---------------------------------------- */
    /* configure system clock */

    /* PLL multiplication factor */
    /*
        Bits 21:18 PLLMUL: PLL multiplication factor
            These bits are written by software to define the PLL multiplication factor. These bits can be
            written only when PLL is disabled.
            Caution: The PLL output frequency must not exceed 72 MHz.

            1110: PLL input clock x 16
            1111: PLL input clock x 16
    */
    RCC_CFGR |= (0b1111 << 18);

    /* select PLL as system clock */
    /*
        Bits 1:0 SW: System clock switch
            Set and cleared by software to select SYSCLK source.
            Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
            failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
            System is enabled).
            00: HSI selected as system clock
            01: HSE selected as system clock
            10: PLL selected as system clock
            11: not allowed
    */
    RCC_CFGR |= (0b10 << 0);

    /* APB1 prescaler (PCLK1 = HCLK/2) */
    /*
        Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
            Set and cleared by software to control the division factor of the APB low-speed clock
            (PCLK1).
            Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
            0xx: HCLK not divided
            100: HCLK divided by 2
            101: HCLK divided by 4
            110: HCLK divided by 8
            111: HCLK divided by 16
    */
    RCC_CFGR |= (0b100 << 8);

    /* APB2 prescaler (PCLK2 = HCLK) */
    /*
        Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
            Set and cleared by software to control the division factor of the APB high-speed clock
            (PCLK2).
            0xx: HCLK not divided
            100: HCLK divided by 2
            101: HCLK divided by 4
            110: HCLK divided by 8
            111: HCLK divided by 16
    */
    RCC_CFGR |= (0b000 << 11);

    /* enable PLL instead of HSI_RC */
    /*
        Bit 24 PLLON: PLL enable
            Set and cleared by software to enable PLL.
            Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
            PLL clock is used as system clock or is selected to become the system clock.
            0: PLL OFF
            1: PLL ON
    */
    RCC_CR |= (1<<24);

    /* ---------------------------------------- */
    /* enable clock for GPIO Port A */

    /* GPIOA clock init */
    /*
        Bit 2 IOPAEN: IO port A clock enable
            Set and cleared by software.
            0: IO port A clock disabled
            1: IO port A clock enabled
    */
    RCC_APB2ENR |= (1<<2);

    /* enable clock for AFIO */

    /* AFIO clock init */
    /*
        Bit 0 AFIOEN: Alternate function IO clock enable
            Set and cleared by software.
            0: Alternate Function IO clock disabled
            1: Alternate Function IO clock enabled
    */
    RCC_APB2ENR |= (1<<0);

    /* ---------------------------------------- */
    /* configure pin 13 in Port A to be output */

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

    /* configure pin 0 in Port A to be input */

    /* Bit 3:2 in CRL Register */
    /*
        In input mode (MODE[1:0]=00):
        01: Floating input (reset state)
    */

    /* Bit 1:0 in CRL Register */
    /* 00: Input mode (reset state) */

    /* Bit 3:0 will be 0100 (0x4) */
    GPIOA_CRL &= 0xFFFFFFF0;
    GPIOA_CRL |= 0x00000004;

    /* ---------------------------------------- */
    /* configure EXTI line 0 to Port A pin 0, enabled and detected at rising edge */

    /* configure EXTI line 0 to Port A pin 0 */
    /*
        Bits 15:0  EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
            These bits are written by software to select the source input for EXTIx external interrupt.
            Refer to Section 10.2.5: External interrupt/event line mapping
            0000: PA[x] pin
            0001: PB[x] pin
            0010: PC[x] pin
            0011: PD[x] pin
            0100: PE[x] pin
            0101: PF[x] pin
            0110: PG[x] pin
    */
    AFIO_EXTICR1 |= (0b0000 << 0);

    /* enable EXTI line 0 */
    /*
        Bits 19:0 MRx: Interrupt Mask on line x
            0: Interrupt request from Line x is masked
            1: Interrupt request from Line x is not masked
    */
    EXTI_IMR |= (1<<0);

    /* enable rising trigger */
    /*
        Bits 19:0 TRx: Rising trigger event configuration bit of line x
            0: Rising trigger disabled (for Event and Interrupt) for input line
            1: Rising trigger enabled (for Event and Interrupt) for input line
    */
    EXTI_RTSR |= (1<<0);

    /* ---------------------------------------- */
    /* configure NVIC to enable EXTI line 0 */

    /* EXTI line 0 (EXTI0) is set as interrupt request number 6 in interrupt vector table */
    /* 
        Position : 6 (IRQ number)
        Priority : 13
        Type of priority : settable
        Acronym : EXTI0
        Description : EXTI Line0 interrupt
        Address : 0x0000_0058
    */
    /* enable NVIC IRQ 6 (EXTI0) */
    NVIC_ISER0 |= (1<<6);
}

/* EXTI Line0 interrupt */
void EXTI0_IRQHandler(void)
{
    /* EXTI 0 detected at rising edge */

    /* toggle led connected to pin 13 */
    GPIOA_ODR ^= (1<<13);

    /* clear pending request from EXTI line 0 */
    /*
        Bits 19:0 PRx: Pending bit
            0: No trigger request occurred
            1: selected trigger request occurred
            This bit is set when the selected edge event arrives on the external interrupt line. This bit is
            cleared by writing a '1' into the bit.
    */
    EXTI_PR |= (1<<0);
}