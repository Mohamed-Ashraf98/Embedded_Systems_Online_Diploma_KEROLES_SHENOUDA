
#include "uart.h"

void uart_send_string(uint8 *ptr_tx_string)
{
    while(*ptr_tx_string != '\0')
    {
        /* loop until null char is found */
        UART0DR = (uint32)(*ptr_tx_string);  /* transmit char */
        ptr_tx_string++;                     /* next char */
    }
}