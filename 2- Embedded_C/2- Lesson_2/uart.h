
#ifndef _UART_H_
#define _UART_H_

#include "Platforms_Types.h"

#define UART0_BASE  0x101F1000
#define UART0DR     *(vuint32_t *const)(UART0_BASE + 0x0)

void uart_send_string(uint8 *ptr_tx_string);

#endif //_UART_H_