
#include "uart.h"

uint8 str[50] = "learn-in-depth : Mohamed Ashraf El-Sayed";

void main(void)
{
    /* versatilepb board */
    uart_send_string(str);
}