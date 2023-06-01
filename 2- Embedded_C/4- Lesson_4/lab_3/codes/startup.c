/*
startup.c for ARM Cortex-M4
learn_in_depth
unit_3 lesson_4 lab_3
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


/* booking 1024 Bytes in .bss section through uninitialized array
    of 256 elements of type int as (256 elements * 4 bytes = 1024 bytes) */
static uint32 stack_top[256];


/* create an array of pointers to functions that take nothing and return void */
/* g_arr_ptr_fn_vectors is an array, each element is a constant pointer to function
    that takes nothing and return void */
void (*const g_arr_ptr_fn_vectors[])() __attribute__((section(".vectors"))) = {

    (void (*)()) ( stack_top + ( sizeof(stack_top)/sizeof(stack_top[0]) ) ),
    &Reset_handler,
    &NMI_handler,
    &H_fault_handler,
    &MM_fault_handler,
    &Bus_fault_handler,
    &Usage_fault_handler
};


extern uint32 _END_TEXT;
extern uint32 _START_DATA;
extern uint32 _END_DATA;
extern uint32 _START_BSS;
extern uint32 _END_BSS;

void Reset_handler()
{
    uint32 i = 0;                              /* counter to traverse the memory */

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