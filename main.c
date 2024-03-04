/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: ad
 */

/******************* Include  Section Start *******************/
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"
#include "HAL/keypad/keypad_HAL_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include <util/delay.h>

#include "MCAL/ADC/ADC_initerface.h"

/**************************************************************/



void testADC_interrupt();

int main(){


	/****************** Testing Interrupt Driver ******************/
//	EXTI_enuInit(EXTI_GroupConfig);
//	DIO_enuSetPinDirection(DIO_u8PortD, DIO_u8PIN2, DIO_u8INPUT);
//	GIE_enuEnable();
//	EXTI_enuEnableInterrupt(1);
//	EXTI_enuSetSenseLevel(1, EXTI_RISING_EDGE);
//	EXTI_enuSetCallBack(warningSequence, 1);
	/**************************************************************/


	/************** Testing LCD Driver **************/
	LCD_enuInit();
	LCD_u8SendString("Ahmed Asl");
	LCD_u8SetPosXY(0, 2);
	/************************************************/


//	/************** Testing ADC Driver without interrupt **************/
//	ADC_enuInit();
//	DIO_enuSetPinDirection(DIO_u8PortA, DIO_u8PIN0, DIO_u8INPUT);
//	uint16 AnalogReadingValue = 0;
//	ADC_enuStartConversion(ADC_Channel_0);
//	AnalogReadingValue = (ADC_GetResult() * ((uint32_t)5000000/ 1024ul))/10000ul;
//
//	/************************************************/



	ADC_enuInit();
	DIO_enuSetPinDirection(DIO_u8PortA, DIO_u8PIN0, DIO_u8INPUT);

	ADC_enuEnableInterrupt();
	GIE_enuEnable();

	ADC_enuSetCallBack(testADC_interrupt);
	ADC_enuStartConversion(ADC_Channel_0);
	while(1){








		_delay_ms(1000);
	}



	    return 0;
}

void testADC_interrupt(){

	uint16 AnalogReadingValue =  (ADC_GetResult() * ((uint32_t)5000000/ 1024ul))/10000ul;
	LCD_enuIntegerToString(AnalogReadingValue, 10);
}


