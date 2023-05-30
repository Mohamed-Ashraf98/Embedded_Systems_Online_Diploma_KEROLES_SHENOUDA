/*
startup.c for ARM Cortex-M3
learn_in_depth
unit_3 lesson_3 lab_2
Mohamed Ashraf El-Sayed
*/

#include "Platforms_Types.h"


void Reset_handler();
void Default_Handler();
int main(void);

void NMI_handler() __attribute__((weak, alias ("Default_Handler")));
void H_fault_handler() __attribute__((weak, alias ("Default_Handler")));
void MM_fault_handler() __attribute__((weak, alias ("Default_Handler")));
void Bus_fault_handler() __attribute__((weak, alias ("Default_Handler")));
void Usage_fault_handler() __attribute__((weak, alias ("Default_Handler")));


extern uint32 _stack_top;
uint32 vectors[] __attribute__((section(".vectors"))) = {

    (uint32) &_stack_top,
    (uint32) &Reset_handler,
    (uint32) &NMI_handler,
    (uint32) &H_fault_handler,
    (uint32) &MM_fault_handler,
    (uint32) &Bus_fault_handler,
    (uint32) &Usage_fault_handler
};


extern uint32 _END_TEXT;
extern uint32 _START_DATA;
extern uint32 _END_DATA;
extern uint32 _START_BSS;
extern uint32 _END_BSS;

void Reset_handler()
{
    vuint32_t i = 0;                           /* counter to traverse the memory */

    /* copy data section from flash to SRAM */
    uint32 DATA_SIZE = (uint8 *)&_END_DATA - (uint8 *)&_START_DATA;
    uint8 *ptr_src = (uint8 *)&_END_TEXT;      /* source : from flash */
    uint8 *ptr_dst = (uint8 *)&_START_DATA;    /* destination : to SRAM */
    for(i = 0; i < DATA_SIZE; i++)
    {
        *((uint8 *)ptr_dst++) = *((uint8 *)ptr_src++);
    }

    /* initialize bss section in SRAM by zero */
    uint32 BSS_SIZE = (uint8 *)&_END_BSS - (uint8 *)&_START_BSS;
    ptr_dst = (uint8 *)&_START_BSS;            /* destination : in SRAM */
    for(i = 0; i < BSS_SIZE; i++)
    {
        *((uint8 *)ptr_dst++) = (uint8)0;
    }
    
    /* jump to main */
    main();
}

void Default_Handler()
{
    Reset_handler();
}