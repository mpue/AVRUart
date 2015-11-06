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

    int i = 0;

	while(1) {

		uart_puts(itoa(i++, buffer, 10));
		uart_puts("\r\n");

		PORTC ^= 1 << PINC4;
		_delay_ms(500);
	}


}
