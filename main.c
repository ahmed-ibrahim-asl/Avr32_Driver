/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */

/******************** Include  Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TWI/TWI_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include <util/delay.h>


#include "MCAL/TIMER/TIMER_interface.h"
/****************************************************************/



int main(void) {
    DIO_enuSetPinDirection(DIO_u8PortD, DIO_u8PIN5, DIO_u8OUTPUT);
    TIMER1_voidInit();
    TIMER1_voidSetPWM(30, 60); // Set PWM duty cycle to 30%

    while (1) {
        // Main loop
    }

    return 0;
}
