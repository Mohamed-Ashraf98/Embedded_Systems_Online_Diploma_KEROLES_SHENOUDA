/*
linker_script.ld for ARM Cortex-M3
learn_in_depth
unit_3 lesson_3 lab_2
Mohamed Ashraf El-Sayed
*/

MEMORY
{
    flash (RX)  : ORIGIN = 0x00000000, LENGTH = 512M
    SRAM (RWX)  : ORIGIN = 0x20000000, LENGTH = 512M
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
}