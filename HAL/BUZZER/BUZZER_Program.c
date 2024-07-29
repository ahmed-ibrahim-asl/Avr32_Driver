/*
 * BUZZER_Program.c
 *
 *  Created on: Jul 29, 2024
 *      Author: ad
 */

/******************** Include  Section Start ********************/
#include "BUZZER_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
/****************************************************************/



void Buzzer_voidInit(Buzzer_t *Copy_Buzzer){
	 DIO_enuSetPinDirection(Copy_Buzzer->PortID, Copy_Buzzer->PortID, 0);
}

void Buzzeer_voidON(Buzzer_t *Copy_Buzzer){
	DIO_enuSetPinValue(Copy_Buzzer->PortID, Copy_Buzzer->PinID, 1);
}

void Buzzeer_voidOFF(Buzzer_t *Copy_Buzzer){
	DIO_enuSetPinValue(Copy_Buzzer->PortID, Copy_Buzzer->PinID, 0);
}

void Buzzer_voidTOGGLE(Buzzer_t *Copy_Buzzer){
	DIO_enuTogglePinValue(Copy_Buzzer->PortID, Copy_Buzzer->PinID);
}

