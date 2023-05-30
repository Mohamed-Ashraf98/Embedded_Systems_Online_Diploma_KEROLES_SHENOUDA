/*
linker_script.ld for ARM Cortex-M3
learn_in_depth
unit_3 lesson_3 lab_2
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
        *(.vectors)
        *(.text)
        *(.rodata)
    }> flash

    .data :
    {
        *(.data)
    }> flash

    .bss :
    {
        *(.bss)
    }> SRAM
}