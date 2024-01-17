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
/**********************************************************/
int main(){



	LCD_enuInit();



	LCD_u8SetPosXY(0, 2);
	LCD_u8SendString("Ahmed Asl");


	while(1){



	}

	    return 0;
}





