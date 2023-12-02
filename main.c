/*
 * File:   main.c
 */

#include <xc.h>
#include "uart.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

extern unsigned char ch;

static void init_config(void)
{    
    init_uart(2400);
    
    puts("Type Here\n\r");
    
    /* Enabling peripheral interrupt */
    PEIE = 1;
    
    /* Enabling global interrupt */
    GIE = 1;
}

void main(void)
{
    unsigned short wait = 0;
    
    init_config();

    while (1)
    {
        if (ch != '\0')
        {
            putchar(ch);
            
            ch = '\0';
        }
        if (!wait--)
        {
            wait = 50000;
        }
    }
    
    return;
}
