/*
linker_script.ld for ARM Cortex-M3
learn_in_depth
unit_3 lesson_5 lab_4
Mohamed Ashraf El-Sayed
*/

MEMORY
{
    flash (RX)  : ORIGIN = 0x08000000, LENGTH = 128K
    SRAM (RWX)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _END_TEXT = . ;
    }> flash

    .data :
    {
        _START_DATA = . ;
        *(.data)
        . = ALIGN(4);
        _END_DATA = . ;
    }> SRAM AT> flash

    .bss :
    {
        _START_BSS = . ;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _END_BSS = . ;
    }> SRAM

    heap :
    {
        _START_HEAP = . ;
        . = . + 0x1000 ;
        . = ALIGN(4);
        _END_HEAP = .;
    }> SRAM

    stack :
    {
        _START_STACK = . ;
        . = . + 0x1000 ;
        . = ALIGN(4);
        _stack_top = . ;
    }> SRAM
}