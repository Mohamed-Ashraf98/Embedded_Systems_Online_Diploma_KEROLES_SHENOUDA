/*
startup.s for ARM Cortex-M3
learn_in_depth
unit_3 lesson_3 lab_2
Mohamed Ashraf El-Sayed
*/

.section .vectors

.word 0x20001000          /* initialize the stack pointer with the address of stack_top */
.word _reset              /* 1  >> reset handler */
.word _vector_handler     /* 2  >> NMI */
.word _vector_handler     /* 3  >> Hard Fault */
.word _vector_handler     /* 4  >> MM Fault */
.word _vector_handler     /* 5  >> Bus Fault */
.word _vector_handler     /* 6  >> Usage Fault */
.word _vector_handler     /* 7  >> Reserved */
.word _vector_handler     /* 8  >> Reserved */
.word _vector_handler     /* 9  >> Reserved */
.word _vector_handler     /* 10 >> Reserved */
.word _vector_handler     /* 11 >> SV call */
.word _vector_handler     /* 12 >> Debug Reserved */
.word _vector_handler     /* 13 >> Reserved */
.word _vector_handler     /* 14 >> PendSV */
.word _vector_handler     /* 15 >> Systick */
.word _vector_handler     /* 16 >> IRQ0 */
.word _vector_handler     /* 17 >> IRQ1 */
.word _vector_handler     /* 18 >> IRQ2 */
.word _vector_handler     /* 16 >> .... */
            /* to IRQ67 */


.section .text

_reset:
    bl main
    b .

.thumb_func

_vector_handler:
    b _reset