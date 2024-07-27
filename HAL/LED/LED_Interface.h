/*
 * LED_Interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ad
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/******************************************* Include  Section *******************************************/
#include "../../MCAL/DIO/DIO_interface.h"
/********************************************************************************************************/





#define LED_voidInit(Copy_u8LEDPortID, Copy_u8LEDPinID) \
        DIO_enuSetPinDirection(Copy_u8LEDPortID, Copy_u8LEDPinID, DIO_u8OUTPUT);


#define LED_voidON(Copy_u8LEDPortID, Copy_u8LEDPinID) \
        DIO_enuSetPinValue(Copy_u8LEDPortID, Copy_u8LEDPinID, DIO_u8HIGH);



#define LED_voidOFF(Copy_u8LEDPortID, Copy_u8LEDPinID) \
        DIO_enuSetPinValue(Copy_u8LEDPortID, Copy_u8LEDPinID, DIO_u8LOW);


#define LED_voidTOGGLE(Copy_u8LEDPortID, Copy_u8LEDPinID) \
        DIO_enuTogglePinValue(Copy_u8LEDPortID, Copy_u8LEDPinID);


#endif /* HAL_LED_LED_INTERFACE_H_ */
