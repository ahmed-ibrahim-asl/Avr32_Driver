/*
 * servo_program.c
 *
 *  Created on: Oct 11, 2024
 *      Author: ad
 */


/******************************************* Include  Section *******************************************/
#include "servo_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"
/********************************************************************************************************/




//ErrorStatus_t DIO_enuSetPinDirection(
//	uint8_t Copy_u8PortID,
//	uint8_t Copy_u8PinID,
//	uint8_t Copy_u8Direction){

void servo_init(){

	/***
	 * - Ensure the TIMER_config.h file is configured for Timer1
	 * - For more precise angle control, choose prescaler lower than 8 (ex. 1)
	 * - you can output two different signals at channel A and Channel B
	 */


	TIMER1_voidInit();
}



void servo_SetAngle(uint8_t copy_u8Angle,  uint8_t copy_u8Channel) {
    // Step 1: Convert the angle to Ton (pulse width) in milliseconds
    double tonMilliseconds = 1000.0 + ((double)copy_u8Angle / 180.0) * 1000.0;

    // Step 2: Calculate the duty cycle for the PWM signal (period = 20 ms for 50 Hz)
    double dutyCycle = (tonMilliseconds / 20000.0) * 100.0;  // Convert pulse width to percentage of 20 ms period

    // Step 3: Set the PWM signal with the calculated duty cycle and fixed 50 Hz frequency
    TIMER1_voidSetPWM_16bit(dutyCycle, 50, copy_u8Channel);  // Use the provided function
}

