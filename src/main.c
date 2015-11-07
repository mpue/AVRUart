/*
 * main.c
 *
 *  Created on: 06.11.2015
 *      Author: mpue
 */

#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

#define setPin(PORT,PIN) PORT |= (1 << PIN)
#define clearPin(PORT,PIN) PORT &= ~(1 << PIN)

#define UART_BAUD_RATE      9600

int main(void) {

	setPin(DDRC,4);

	char buffer[4];


    /*
     *  Initialize UART library, pass baudrate and AVR cpu clock
     *  with the macro
     *  UART_BAUD_SELECT() (normal speed mode )
     *  or
     *  UART_BAUD_SELECT_DOUBLE_SPEED() ( double speed mode)
     */
    uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

    /*
     * now enable interrupt, since UART library is interrupt controlled
     */
    sei();

    unsigned int c;


    uart_puts("Ready.\r\n");

	while(1) {

        /*
         * Get received character from ringbuffer
         * uart_getc() returns in the lower byte the received character and
         * in the higher byte (bitmask) the last receive error
         * UART_NO_DATA is returned when no data is available.
         *
         */
        c = uart_getc();

        if ( c & UART_NO_DATA )
        {
            /*
             * no data available from UART
             */
        }
        else
        {
            /*
             * new data available from UART
             * check for Frame or Overrun error
             */
            if ( c & UART_FRAME_ERROR )
            {
                /* Framing Error detected, i.e no stop bit detected */
                uart_puts_P("UART Frame Error: ");
            }
            if ( c & UART_OVERRUN_ERROR )
            {
                /*
                 * Overrun, a character already present in the UART UDR register was
                 * not read by the interrupt handler before the next character arrived,
                 * one or more received characters have been dropped
                 */
                uart_puts_P("UART Overrun Error: ");
            }
            if ( c & UART_BUFFER_OVERFLOW )
            {
                /*
                 * We are not reading the receive buffer fast enough,
                 * one or more received character have been dropped
                 */
                uart_puts_P("Buffer overflow error: ");
            }
            /*
             * send received character back
             */

            // PORTC ^= 1 << PINC4;

            if ((unsigned char)c == 'n') {
            	setPin(PORTC,4);
            	uart_puts("On.\r\n");
            }
            else if ((unsigned char)c ==  'm') {
            	clearPin(PORTC,4);
            	uart_puts("Off.\r\n");
            }

            // uart_putc( (unsigned char)c );

        }
	}


}
