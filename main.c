/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */


/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include "MCAL/uart/UART_interface.h"
#include "MCAL/uart/UART_config.h"
#include <util/delay.h>
#include <avr/io.h>
/****************************************************************/



int main(){


	UART_setBaudRate(9600);
    UCSRB |= (1<<RXEN) | (1<<TXEN); // Enable receiver and transmitter


	//////////////////////////////////////////////////////////////////


    UART_vidInit(9600);
    _delay_ms(1000); // Wait for a moment



    while (1) {

        UART_enuSendString((uint8_t*)"Hello World\r\n");
        _delay_ms(1000);
    }

	return 0;
}







