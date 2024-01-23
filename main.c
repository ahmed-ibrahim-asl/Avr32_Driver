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


//	LCD_enuSendData('b');
//	LCD_u8SetPosXY(10, 2);
//	LCD_u8SendString("Ahmed Asl");
//
//	LCD_enuSendData('a');
//	LCD_enuSendData('h');

//
//	LCD_u8SetPosXY(0, 2);
//	LCD_enuSendData('0');
	uint8_t test = 'A';

	while(1){



		LCD_enuSendData(test++);

		_delay_ms(1);
	}

	    return 0;
}





