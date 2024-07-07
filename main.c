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


int main(){


	TIMER1_voidInit();


	TIMER1_voidSetPWM(10);




	while(1){


	}


	    return 0;
}


