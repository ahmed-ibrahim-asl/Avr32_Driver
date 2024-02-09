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

void warningSequence();
int main(){


	LCD_enuInit();
	keypad_enuInit();
//!	EXTI_enuInit(EXTI_GroupConfig);

	DIO_enuSetPinDirection(DIO_u8PortD, DIO_u8PIN2, DIO_u8INPUT);
	GIE_enuEnable();


	EXTI_enuEnableInterrupt(INT0);
	EXTI_enuSetSenseLevel(INT0, EXTI_RISING_EDGE);
	EXTI_enuSetCallBack(warningSequence, INT0);





	while(1){



	}
	    return 0;
}

void warningSequence(){
	LCD_u8SendString("WARNING");
}

