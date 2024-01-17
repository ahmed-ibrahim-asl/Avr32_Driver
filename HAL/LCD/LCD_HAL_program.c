/*
 * LCD_HAL_program.c
 *
 *  Created on: Jan 5, 2024
 *      Author: ad
 */


/*************** Include Section Start ********************/
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_HAL_priv.h"
#include "LCD_HAL_config.h"
#include "LCD_HAL_interface.h"
/**********************************************************/




/**********************************************************/
static ErrorStatus_t WriteNLatch(uint8_t Copy_u8Data);

/**********************************************************/


ErrorStatus_t LCD_enuInit(void){



	ErrorStatus_t Local_enuErrrorState = ERROR_STATUS_FAILURE;


	/******************* !Control Pins! *******************/
	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RS_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RS_PORT, EN_PIN, DIO_u8OUTPUT);
	/***************************************************/


	/******************** !Data Pins! ********************/
	// I choose these pins because they are common
	// among 4bit and 8bit lcd modes.
	DIO_enuSetPinDirection(DB7_PORT, DB7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DB6_PORT, DB6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DB5_PORT, DB5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DB4_PORT, DB4_PIN, DIO_u8OUTPUT);

	_delay_ms(POWER_ON_DELAY);
	#if(LCD_MODE == EIGHT_BIT)

		DIO_enuSetPinDirection(DB3_PORT, DB3_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DB2_PORT, DB2_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DB1_PORT, DB1_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DB0_PORT, DB0_PIN, DIO_u8OUTPUT);
	#endif

	/***************************************************/

	#if(LCD_MODE == FOUR_BIT)

		/******************** !Function Set! ********************/
		LCD_enuSendCommand(0b0010);
		SEND_ENABLE_PULSE();
		LCD_enuSendCommand(0b0010);
		SEND_ENABLE_PULSE();

		/**
		 * NFxx
		 *
		 * N - Number of lines
		 * 		(0 - oneline | 1 - twolines)
		 *
		 * F - Font
		 * 		(0 - 5x7dot matrix)
		 * 			means 5dot in width and 7dot in height
		 * */


		LCD_enuSendCommand(0b1000);
		SEND_ENABLE_PULSE();
		/******************************************************/



	#endif


	#if(LCD_MODE == EIGHT_BIT)

		/******************** !Function Set! ********************/
		/**
		 * 0b0011NFxx
		 *
		 * N - Number of lines
		 * 		(0 - oneline | 1 - twolines)
		 *
		 * F - Font
		 * 		(0 - 5x7dot matrix)
		 * 			means 5dot in width and 7dot in height
		 * */

		LCD_enuSendCommand(0b00111000);
		_delay_ms(FUNCTION_SET_DELAY);
		/******************************************************/
	#endif

	/******************* !Display ON/OFF! *******************/
	/**
	 *	1DCBxxxx
	 *
	 * D - Controls the Display on or off
     * C - Controls Cursor on or off
     * B - Control Blinking of cursor position
     * x - don't care
     * */


	LCD_enuSendCommand(0b00001100);
	/******************************************************/


	/******************* !Display CLEAR! *******************/
	LCD_enuSendCommand(CLEAR);
	/******************************************************/

	#ifndef LCD_MODE
		#warning "LCD_MODE Macro is not defined"
		return Local_enuErrrorState;
	#endif

	Local_enuErrrorState = ERROR_STATUS_OK;

	return Local_enuErrrorState;
}


static ErrorStatus_t WriteNLatch(uint8_t Copy_u8Data){

    ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;

    #if(LCD_MODE == FOUR_BIT)

        // Send Higher Nibble
        DIO_enuSetPinValue(LCD_DATA_PORT, DB4_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_5));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB5_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_6));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB6_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_7));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB7_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_8));

        SEND_ENABLE_PULSE();

        // Send Lower Nibble
        DIO_enuSetPinValue(LCD_DATA_PORT, DB4_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_1));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB5_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_2));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB6_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_3));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB7_PIN, GET_BIT(Copy_u8Data, LCD_DATA_BIT_4));

        SEND_ENABLE_PULSE();

    #elif(LCD_MODE == EIGHT_BIT)

        DIO_enuSetPinValue(LCD_DATA_PORT, DB4_PIN, GET_BIT(Copy_u8Data, 4));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB5_PIN, GET_BIT(Copy_u8Data, 5));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB6_PIN, GET_BIT(Copy_u8Data, 6));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB7_PIN, GET_BIT(Copy_u8Data, 7));

        DIO_enuSetPinValue(LCD_DATA_PORT, DB4_PIN, GET_BIT(Copy_u8Data, 0));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB5_PIN, GET_BIT(Copy_u8Data, 1));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB6_PIN, GET_BIT(Copy_u8Data, 2));
        DIO_enuSetPinValue(LCD_DATA_PORT, DB7_PIN, GET_BIT(Copy_u8Data, 3));
        SEND_ENABLE_PULSE();

    #else
        #warning "Wrong LCD MODE"
        return Local_enu_ErrorState;

    #endif

    Local_enu_ErrorState = ERROR_STATUS_OK;
    return Local_enu_ErrorState;
}

ErrorStatus_t LCD_enuSendData(uint8_t Copy_u8Data){


	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;

						 

	// RS-> held to high since we are going to send data 
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);



	WriteNLatch(Copy_u8Data);



	return Local_enu_ErrorState;
}
ErrorStatus_t LCD_enuSendCommand(uint8_t Copy_u8Command){




	ErrorStatus_t Local_enu_ErrorState = ERROR_STATUS_FAILURE;

						 
	// RS -> held to low since we are going to send command
	// RW -> held to low, because we writing on LCD
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	WriteNLatch(Copy_u8Command);




	Local_enu_ErrorState = ERROR_STATUS_OK;

	return Local_enu_ErrorState;
}


ErrorStatus_t LCD_u8SendString(const char *Copy_pu8String){


	ErrorStatus_t Local_enuErrrorState = ERROR_STATUS_FAILURE;
	if(Copy_pu8String != NULL){
		uint8_t local_u8counter = 0;

		// condition tests whether we reached end of given text
		while(Copy_pu8String[local_u8counter] != '\0'){
			LCD_enuSendData(Copy_pu8String[local_u8counter++]);
		}
	}else{

		Local_enuErrrorState = ERROR_STATUS_OK;
		return Local_enuErrrorState;
	}

	return Local_enuErrrorState;
}



ErrorStatus_t LCD_enuIntegerToString(sint32_t Copy_u8data, uint8_t Copy_u8Base){

	ErrorStatus_t Local_enuErrrorState = ERROR_STATUS_FAILURE;

	// To handle store given number as string & converting process
	char  Copy_u8Buffer[20];
	uint8_t Local_u8Counter = 0;
	uint8_t Local_u8NumberIndex= 0;


	// To handle reversing the string
	uint8_t Local_u8Start = 0;
	uint8_t Local_u8End   = 0;
	uint8_t Local_u8temp;


	//Handle Negative Numbers
	if(Copy_u8data < 0){
		LCD_enuSendData('-');
		Copy_u8data*=-1;
	}


	if(Copy_u8data == 0){
		Copy_u8Buffer[Local_u8Counter++] = '0';
		Copy_u8Buffer[Local_u8Counter] = '\0';

		return Local_enuErrrorState;
	}



	else{


		while(Copy_u8data != 0){
			Local_u8NumberIndex = (Copy_u8data%Copy_u8Base);

			Copy_u8Buffer[Local_u8Counter++] = (Local_u8NumberIndex)+'0';

			Copy_u8data /= Copy_u8Base;
		}

	    Copy_u8Buffer[Local_u8Counter] = '\0';

	}

	Local_u8End = Local_u8Counter-1;
    // Reverse Buffer
	while(Local_u8Start < Local_u8End){
    	Local_u8temp = Copy_u8Buffer[Local_u8Start];

        Copy_u8Buffer[Local_u8Start] = Copy_u8Buffer[Local_u8End];
        Copy_u8Buffer[Local_u8End] = Local_u8temp;

        Local_u8Start++;
        Local_u8End--;
    }

	LCD_u8SendString(Copy_u8Buffer);

	Local_enuErrrorState = ERROR_STATUS_OK;
	return Local_enuErrrorState;
}



//! Is not working
ErrorStatus_t LCD_u8SetPosXY(uint8_t copy_u8PosX,uint8_t copy_u8PosY)
{
	ErrorStatus_t local_u8ErrorState=ERROR_STATUS_OK;


	unsigned int local_u8DDRAM=0;

	switch(copy_u8PosY)
	{
		case 1:
			local_u8DDRAM = copy_u8PosX;
			break;

		case 2:
			local_u8DDRAM= copy_u8PosX+0x40;
			break;

		default:
			local_u8ErrorState=ERROR_STATUS_FAILURE;
		break;
	}


	SET_BIT(local_u8DDRAM,7); // From datasheet

	LCD_enuSendCommand(local_u8DDRAM);

	return local_u8ErrorState;
}

