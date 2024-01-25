/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */

/*************** Include Section Start ********************/
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include "HAL/keypad/keypad_HAL_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include <util/delay.h>
/**********************************************************/
int main(){



	LCD_enuInit();
	keypad_enuInit();






	LCD_u8DisplayCustomChar(0, 0, 0);

	while(1){


//
//		LCD_enuSendData(test++);
//
//		_delay_ms(1);
	}

	    return 0;
}





