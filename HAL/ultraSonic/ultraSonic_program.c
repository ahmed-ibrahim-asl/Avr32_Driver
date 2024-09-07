/*
 * ultraSonic_program.c
 *
 *  Created on: Sep 7, 2024
 *      Author: ad
 */


/************************ Include Section ************************/
#include "../../MCAL/DIO/helper_embedded_libraries/micro_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"
#include "../../MCAL/TIMER/TIMER_priv.h"
#include <util/delay.h>
#include "ultraSonic_interface.h"
/*****************************************************************/



ErrorStatus_t ultraSonic_enuInit(ultraSonic_t ultraSonic_Instance){
	ErrorStatus_t Local_enuErrrorState = ERROR_STATUS_FAILURE;



    if (ultraSonic_Instance.ECHO_PORT < DIO_u8PortA ||
    	ultraSonic_Instance.ECHO_PORT > DIO_u8PortD ||
        ultraSonic_Instance.ECHO_PIN < DIO_u8PIN0 || ultraSonic_Instance.ECHO_PIN > DIO_u8PIN7) {

    	return Local_enuErrrorState;  // Return failure if the ECHO_PORT or ECHO_PIN are invalid

    } else {

    	Timer1_SetupForTimeMeasurement(8);
    	DIO_enuSetPinDirection(ultraSonic_Instance.ECHO_PORT, ultraSonic_Instance.ECHO_PIN, DIO_u8INPUT);
    	DIO_enuSetPinDirection(ultraSonic_Instance.TRIG_PORT, ultraSonic_Instance.TRIG_PIN, DIO_u8OUTPUT);

    }




	Local_enuErrrorState = ERROR_STATUS_OK;
	return Local_enuErrrorState;
}



void ultraSonic_u16GetDistance(ultraSonic_t* ultraSonic_Instance){
	uint8_t Local_u8EchoPinStatus = 0;

	// Send a 10µs pulse to the trigger pin
	DIO_enuSetPinValue(ultraSonic_Instance->TRIG_PORT, ultraSonic_Instance->TRIG_PIN, DIO_u8HIGH);

	_delay_us(10);

	DIO_enuSetPinValue(ultraSonic_Instance->TRIG_PORT, ultraSonic_Instance->TRIG_PIN, DIO_u8LOW);


	// Wait for echo pin to go high, indicating the start of distance measurement

	DIO_enuGetPinValue(ultraSonic_Instance->ECHO_PORT, ultraSonic_Instance->ECHO_PIN, &Local_u8EchoPinStatus);
	while(!Local_u8EchoPinStatus){
		DIO_enuGetPinValue(ultraSonic_Instance->ECHO_PORT, ultraSonic_Instance->ECHO_PIN, &Local_u8EchoPinStatus);
	}

	RESET_TIMER1();

	// Wait for echo pin to go low (reflected pulse received)

	DIO_enuGetPinValue(ultraSonic_Instance->ECHO_PORT, ultraSonic_Instance->ECHO_PIN, &Local_u8EchoPinStatus);
	while(Local_u8EchoPinStatus){
		DIO_enuGetPinValue(ultraSonic_Instance->ECHO_PORT, ultraSonic_Instance->ECHO_PIN, &Local_u8EchoPinStatus);
	}

	ultraSonic_Instance->measuredDistance_InCm = TIMER1_u16ReadCount() / 58;
}
