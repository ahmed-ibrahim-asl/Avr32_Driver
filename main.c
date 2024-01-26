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




	uint8_t Local_u8KeypadValue = 0;


	while(1){

		if(keypad_enuGetPressedKey(&Local_u8KeypadValue) != ERROR_STATUS_FAILURE){


			if(Local_u8KeypadValue == 'K'){
				LCD_enuSendCommand(0X01);
			}

			else{
				LCD_enuSendData(Local_u8KeypadValue);
			}

	}

	}
	    return 0;
}





